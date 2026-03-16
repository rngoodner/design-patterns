#ifndef STATE_HPP
#define STATE_HPP

#include <random>

// forward declaration to allow states to reference the machine
class GumballMachine;

// state interface
class State {
public:
    virtual ~State() = default;
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

// concrete states
class NoQuarterState : public State {
public:
    explicit NoQuarterState(GumballMachine& machine);
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& m_machine;
};

class HasQuarterState : public State {
public:
    explicit HasQuarterState(GumballMachine& machine);
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& m_machine;
};

class SoldState : public State {
public:
    explicit SoldState(GumballMachine& machine);
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& m_machine;
};

// WinnerState: like SoldState but releases two gumballs (1-in-10 prize)
class WinnerState : public State {
public:
    explicit WinnerState(GumballMachine& machine);
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;

private:
    GumballMachine& m_machine;
};

// sold out state has no need to call back into the machine
class SoldOutState : public State {
public:
    void insertQuarter() override;
    void ejectQuarter() override;
    void turnCrank() override;
    void dispense() override;
};

// context: delegates all actions to the current state object
class GumballMachine {
public:
    explicit GumballMachine(int count, unsigned seed = 11);
    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void releaseBall();
    int getCount() const;
    void setState(State& state);
    void print() const;

private:
    // state objects are internal collaborators; they access state getters directly
    friend class NoQuarterState;
    friend class HasQuarterState;
    friend class SoldState;
    friend class WinnerState;

    State& getNoQuarterState();
    State& getHasQuarterState();
    State& getSoldState();
    State& getWinnerState();
    State& getSoldOutState();

    NoQuarterState m_noQuarterState;
    HasQuarterState m_hasQuarterState;
    SoldState m_soldState;
    WinnerState m_winnerState;
    SoldOutState m_soldOutState;
    std::mt19937 m_rng;
    State* m_currentState;
    int m_count;
};

#endif // STATE_HPP
