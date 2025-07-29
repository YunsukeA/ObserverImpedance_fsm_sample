#include "ObserverbasedImpedanceFSMSample_Initial.h"

#include "../ObserverbasedImpedanceFSMSample.h"

void ObserverbasedImpedanceFSMSample_Initial::configure(const mc_rtc::Configuration & config)
{
}

void ObserverbasedImpedanceFSMSample_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<ObserverbasedImpedanceFSMSample &>(ctl_);
}

bool ObserverbasedImpedanceFSMSample_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<ObserverbasedImpedanceFSMSample &>(ctl_);
  output("OK");
  return true;
}

void ObserverbasedImpedanceFSMSample_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<ObserverbasedImpedanceFSMSample &>(ctl_);
}

EXPORT_SINGLE_STATE("ObserverbasedImpedanceFSMSample_Initial", ObserverbasedImpedanceFSMSample_Initial)
