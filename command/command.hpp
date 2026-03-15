#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <array>
#include <memory>
#include <string>

// command interface
class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// NoCommand — null object; used to initialize empty slots so null checks are never needed
class NoCommand : public Command {
public:
    void execute() override { }
    void undo() override { }
};

// Light receiver
class Light {
public:
    explicit Light(std::string location);
    void on();
    void off();

private:
    std::string m_location;
};

class LightOnCommand : public Command {
public:
    explicit LightOnCommand(Light& light);
    void execute() override;
    void undo() override;

private:
    Light& m_light;
};

class LightOffCommand : public Command {
public:
    explicit LightOffCommand(Light& light);
    void execute() override;
    void undo() override;

private:
    Light& m_light;
};

// CeilingFan receiver
class CeilingFan {
public:
    explicit CeilingFan(std::string location);
    void high();
    void off();

private:
    std::string m_location;
};

class CeilingFanHighCommand : public Command {
public:
    explicit CeilingFanHighCommand(CeilingFan& fan);
    void execute() override;
    void undo() override;

private:
    CeilingFan& m_fan;
};

class CeilingFanOffCommand : public Command {
public:
    explicit CeilingFanOffCommand(CeilingFan& fan);
    void execute() override;
    void undo() override;

private:
    CeilingFan& m_fan;
};

// RemoteControl invoker — seven on/off slots; NoCommand fills unused slots
class RemoteControl {
public:
    static constexpr int c_slots = 7;
    RemoteControl();
    void setCommand(int slot, std::unique_ptr<Command> onCmd, std::unique_ptr<Command> offCmd);
    void onButtonWasPushed(int slot);
    void offButtonWasPushed(int slot);
    void undoButtonWasPushed();

private:
    std::array<std::unique_ptr<Command>, c_slots> m_onCommands;
    std::array<std::unique_ptr<Command>, c_slots> m_offCommands;
    Command* m_lastCommand { nullptr };
};

#endif // COMMAND_HPP
