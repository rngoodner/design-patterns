#include "command.hpp"

int main()
{
    Light livingRoomLight { "living room" };
    Light kitchenLight { "kitchen" };
    CeilingFan ceilingFan { "living room" };

    RemoteControl remote;
    remote.setCommand(0, std::make_unique<LightOnCommand>(livingRoomLight), std::make_unique<LightOffCommand>(livingRoomLight));
    remote.setCommand(1, std::make_unique<LightOnCommand>(kitchenLight), std::make_unique<LightOffCommand>(kitchenLight));
    remote.setCommand(2, std::make_unique<CeilingFanHighCommand>(ceilingFan), std::make_unique<CeilingFanOffCommand>(ceilingFan));

    remote.onButtonWasPushed(0);
    remote.onButtonWasPushed(1);
    remote.onButtonWasPushed(2);

    remote.offButtonWasPushed(2);
    remote.undoButtonWasPushed(); // undoes ceiling fan off -> turns it back on high

    remote.offButtonWasPushed(0);
    remote.undoButtonWasPushed(); // undoes living room light off -> turns it back on
}
