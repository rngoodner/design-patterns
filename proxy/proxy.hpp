#ifndef PROXY_HPP
#define PROXY_HPP

#include <memory>
#include <string>

// subject interface
class Image {
public:
    virtual ~Image() = default;
    virtual void display() const = 0;
};

// real subject: loads from disk on construction
class RealImage : public Image {
public:
    explicit RealImage(std::string filename);
    void display() const override;

private:
    void loadFromDisk();
    std::string m_filename;
};

// virtual proxy: defers creation of RealImage until display() is first called
class ProxyImage : public Image {
public:
    explicit ProxyImage(std::string filename);
    void display() const override;

private:
    std::string m_filename;
    mutable std::unique_ptr<RealImage> m_realImage;
};

#endif // PROXY_HPP
