#pragma once

#include <mc_control/fsm/Controller.h>
#include <mc_control/mc_controller.h>
#include <mc_tasks/lipm_stabilizer/StabilizerTask.h>

#include "api.h"

struct ObserverbasedImpedanceFSMSample_DLLAPI ObserverbasedImpedanceFSMSample
    : public mc_control::fsm::Controller {
  ObserverbasedImpedanceFSMSample(mc_rbdyn::RobotModulePtr rm, double dt,
                                  const mc_rtc::Configuration &config);

  bool run() override;

  void reset(const mc_control::ControllerResetData &reset_data) override;

private:
  std::shared_ptr<mc_tasks::lipm_stabilizer::StabilizerTask>
      lipm_stabilizer_ptr_;
};