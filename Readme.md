# Observerbased Impedance FSM Sample

This is a sample controller for mc_rtc that uses Observerbased Impedance Control with an FSM.

## What is Observerbased Impedance Control

Observerbased Impedance Control (OIcontrol) is an observer-based impedance control.
General impedance control requires a force sensor's value as feedback.
OIcontrol receives an estimated force value from [Kinetics Observer](https://github.com/YunsukeA/mc_state_observation) as feedback.

## Requirements

- [mc_rtc](https://github.com/YunsukeA/mc_rtc/tree/feature/dev_Task)
  - With Observerbased Impedance Task
- [mc_state_Observation](https://github.com/YunsukeA/mc_state_observation/tree/submission_TRO_KineticsObserver_24_12)
  - With Kinetics Observer and exportation

Currently, the only available robot is HRP5P.

## Usage

Some examples are available in the `etc` folder.
If you want to use them, please create a symbolic link to each YAML file.

```bash
ln -fsn <your mc_rtc configuration directory>/controllers/ObserverbasedImpedanceFSMSample.yaml <Path to this repository>/etc/<ForearmImpedance or PushTableFSM>/ObserverbasedImpedanceFSMSample.yaml
```

## Example explanation

### TablePushFSM

todo

### ForearmImpedance

todo