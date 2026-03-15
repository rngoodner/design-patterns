#include "command.hpp"

#include <iostream>
#include <utility>

// Light

Light::Light(std::string location)
    : m_location(std::move(location))
{
}

void Light::on()
{
    std::cout << m_location << " light is on\n";
}

void Light::off()
{
    std::cout << m_location << " light is off\n";
}

LightOnCommand::LightOnCommand(Light& light)
    : m_light(light)
{
}

void LightOnCommand::execute() { m_light.on(); }
void LightOnCommand::undo() { m_light.off(); }

LightOffCommand::LightOffCommand(Light& light)
    : m_light(light)
{
}

void LightOffCommand::execute() { m_light.off(); }
void LightOffCommand::undo() { m_light.on(); }

// CeilingFan

CeilingFan::CeilingFan(std::string location)
    : m_location(std::move(location))
{
}

void CeilingFan::high()
{
    std::cout << m_location << " ceiling fan is on high\n";
}

void CeilingFan::off()
{
    std::cout << m_location << " ceiling fan is off\n";
}

CeilingFanHighCommand::CeilingFanHighCommand(CeilingFan& fan)
    : m_fan(fan)
{
}

void CeilingFanHighCommand::execute() { m_fan.high(); }
void CeilingFanHighCommand::undo() { m_fan.off(); }

CeilingFanOffCommand::CeilingFanOffCommand(CeilingFan& fan)
    : m_fan(fan)
{
}

void CeilingFanOffCommand::execute() { m_fan.off(); }
void CeilingFanOffCommand::undo() { m_fan.high(); }

// RemoteControl

RemoteControl::RemoteControl()
{
    for (auto& cmd : m_onCommands)
        cmd = std::make_unique<NoCommand>();
    for (auto& cmd : m_offCommands)
        cmd = std::make_unique<NoCommand>();
    m_lastCommand = m_onCommands[0].get();
}

void RemoteControl::setCommand(int slot, std::unique_ptr<Command> onCmd, std::unique_ptr<Command> offCmd)
{
    m_onCommands[slot] = std::move(onCmd);
    m_offCommands[slot] = std::move(offCmd);
}

void RemoteControl::onButtonWasPushed(int slot)
{
    m_onCommands[slot]->execute();
    m_lastCommand = m_onCommands[slot].get();
}

void RemoteControl::offButtonWasPushed(int slot)
{
    m_offCommands[slot]->execute();
    m_lastCommand = m_offCommands[slot].get();
}

void RemoteControl::undoButtonWasPushed()
{
    m_lastCommand->undo();
}
