#include "stringgenerator.h"

StringGenerator::StringGenerator() 
    : m_useUppercase(true)
    , m_useLowercase(true)
    , m_useNumbers(true)
    , m_useDash(true)
    , m_customCharset("")
    , m_generator(m_rd()) {
}

QString StringGenerator::generateRandomString(int length) {
    QString charset = buildCharset();
    
    // If charset is empty, return empty string
    if (charset.isEmpty()) {
        return QString();
    }
    
    QString result;
    std::uniform_int_distribution<int> distribution(0, charset.length() - 1);
    
    for (int i = 0; i < length; ++i) {
        int index = distribution(m_generator);
        result.append(charset.at(index));
    }
    
    return result;
}

void StringGenerator::setUseUppercase(bool use) {
    m_useUppercase = use;
}

void StringGenerator::setUseLowercase(bool use) {
    m_useLowercase = use;
}

void StringGenerator::setUseNumbers(bool use) {
    m_useNumbers = use;
}

void StringGenerator::setUseDash(bool use) {
    m_useDash = use;
}

void StringGenerator::setCustomCharset(const QString& charset) {
    m_customCharset = charset;
}

QString StringGenerator::getCurrentCharset() const {
    return buildCharset();
}

QString StringGenerator::buildCharset() const {
    // If custom charset is provided, use it exclusively
    if (!m_customCharset.isEmpty()) {
        return m_customCharset;
    }
    
    QString charset;
    
    if (m_useUppercase) {
        charset += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    
    if (m_useLowercase) {
        charset += "abcdefghijklmnopqrstuvwxyz";
    }
    
    if (m_useNumbers) {
        charset += "0123456789";
    }
    
    if (m_useDash) {
        charset += "-";
    }
    
    return charset;
}