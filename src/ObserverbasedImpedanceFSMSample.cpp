#include "ObserverbasedImpedanceFSMSample.h"

ObserverbasedImpedanceFSMSample::ObserverbasedImpedanceFSMSample(
    mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration &config)
    : mc_control::fsm::Controller(rm, dt, config) {
  datastore().make_call("KinematicAnchorFrame::" + robot().name(),
                        [](const mc_rbdyn::Robot &robot) {
                          return sva::interpolate(
                              robot.surfacePose("LeftFoot"),
                              robot.surfacePose("RightFoot"), 0.5);
                        });

  auto stabiConf = robot().module().defaultLIPMStabilizerConfiguration();

  lipm_stabilizer_ptr_ =
      std::make_shared<mc_tasks::lipm_stabilizer::StabilizerTask>(
          solver().robots(), solver().realRobots(), robots().robotIndex(),
          stabiConf.leftFootSurface, stabiConf.rightFootSurface,
          stabiConf.torsoBodyName, solver().dt());
  lipm_stabilizer_ptr_->reset();
  lipm_stabilizer_ptr_->setContacts(
      {mc_tasks::lipm_stabilizer::ContactState::Left,
       mc_tasks::lipm_stabilizer::ContactState::Right});

  lipm_stabilizer_ptr_->configure(stabiConf);
  solver().addTask(lipm_stabilizer_ptr_);

  mc_rtc::log::success("ObserverbasedImpedanceFSMSample init done ");
}

bool ObserverbasedImpedanceFSMSample::run() {
  return mc_control::fsm::Controller::run();
}

void ObserverbasedImpedanceFSMSample::reset(
    const mc_control::ControllerResetData &reset_data) {
  lipm_stabilizer_ptr_.reset();
  mc_control::fsm::Controller::reset(reset_data);
}
