#include "configmanager.h"

ConfigManager::ConfigManager(QObject* parent)
    : QObject(parent)
    , m_useUppercase(true)
    , m_useLowercase(true)
    , m_useNumbers(true)
    , m_useDash(true)
    , m_customCharset("")
    , m_stringLength(10) {
}

void ConfigManager::setUseUppercase(bool use) {
    if (m_useUppercase != use) {
        m_useUppercase = use;
        emit configChanged();
    }
}

bool ConfigManager::useUppercase() const {
    return m_useUppercase;
}

void ConfigManager::setUseLowercase(bool use) {
    if (m_useLowercase != use) {
        m_useLowercase = use;
        emit configChanged();
    }
}

bool ConfigManager::useLowercase() const {
    return m_useLowercase;
}

void ConfigManager::setUseNumbers(bool use) {
    if (m_useNumbers != use) {
        m_useNumbers = use;
        emit configChanged();
    }
}

bool ConfigManager::useNumbers() const {
    return m_useNumbers;
}

void ConfigManager::setUseDash(bool use) {
    if (m_useDash != use) {
        m_useDash = use;
        emit configChanged();
    }
}

bool ConfigManager::useDash() const {
    return m_useDash;
}

void ConfigManager::setCustomCharset(const QString& charset) {
    if (m_customCharset != charset) {
        m_customCharset = charset;
        emit configChanged();
    }
}

QString ConfigManager::customCharset() const {
    return m_customCharset;
}

void ConfigManager::setStringLength(int length) {
    if (m_stringLength != length && length > 0) {
        m_stringLength = length;
        emit configChanged();
    }
}

int ConfigManager::stringLength() const {
    return m_stringLength;
}