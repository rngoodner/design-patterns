#ifndef TEMPLATE_METHOD_HPP
#define TEMPLATE_METHOD_HPP

// abstract class defining the skeleton of the beverage preparation algorithm
class CaffeineBeverage {
public:
    virtual ~CaffeineBeverage() = default;
    // template method: defines the steps; subclasses fill in brew() and addCondiments()
    void prepareRecipe();

private:
    void boilWater();
    void pourInCup();
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    // hook: subclasses may override to skip condiments; default is true
    virtual bool customerWantsCondiments();
};

class FilterCoffee : public CaffeineBeverage {
private:
    void brew() override;
    void addCondiments() override;
};

class SteepedTea : public CaffeineBeverage {
private:
    void brew() override;
    void addCondiments() override;
    // override hook to skip condiments when customer declines
    bool customerWantsCondiments() override;
};

#endif // TEMPLATE_METHOD_HPP
