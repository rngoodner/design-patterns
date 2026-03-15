#ifndef ADAPTER_HPP
#define ADAPTER_HPP

// target interface that clients expect
class Duck {
public:
    virtual ~Duck() = default;
    virtual void quack() const = 0;
    virtual void fly() const = 0;
};

// adaptee interface that is incompatible with Duck
class Turkey {
public:
    virtual ~Turkey() = default;
    virtual void gobble() const = 0;
    virtual void fly() const = 0;
};

// concrete duck
class GreenHeadDuck : public Duck {
public:
    void quack() const override;
    void fly() const override;
};

// concrete adaptee
class WildTurkey : public Turkey {
public:
    void gobble() const override;
    void fly() const override;
};

// adapter: wraps Turkey to look like a Duck
class TurkeyAdapter : public Duck {
public:
    explicit TurkeyAdapter(Turkey& turkey);
    void quack() const override;
    void fly() const override;

private:
    Turkey& m_turkey;
};

#endif // ADAPTER_HPP
