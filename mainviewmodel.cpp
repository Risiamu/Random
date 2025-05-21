#include "mainviewmodel.h"

MainViewModel::MainViewModel(QObject* parent)
    : QObject(parent)
    , m_stringGenerator(new StringGenerator())
    , m_historyManager(new HistoryManager(this))
    , m_configManager(new ConfigManager(this)) {
    
    // Connect the config manager's signal to update the string generator
    connect(m_configManager, &ConfigManager::configChanged, this, &MainViewModel::updateStringGenerator);
    
    // Initialize the string generator with current configuration
    updateStringGenerator();
}

MainViewModel::~MainViewModel() {
    delete m_stringGenerator;
}

QString MainViewModel::generateString() {
    // Generate a string with the current configuration
    QString generatedString = m_stringGenerator->generateRandomString(m_configManager->stringLength());
    
    // Add the string to history
    if (!generatedString.isEmpty()) {
        m_historyManager->addString(generatedString);
        emit stringGenerated(generatedString);
    }
    
    return generatedString;
}

void MainViewModel::copyToClipboard(const QString& str) {
    // Don't copy empty strings
    if (str.isEmpty()) {
        return;
    }
    
    // Copy the string to clipboard
    QClipboard* clipboard = QApplication::clipboard();
    clipboard->setText(str);
    
    emit stringCopied(str);
}

QStringList MainViewModel::getHistory() const {
    return m_historyManager->getHistory();
}

void MainViewModel::clearHistory() {
    m_historyManager->clearHistory();
}

ConfigManager* MainViewModel::getConfigManager() const {
    return m_configManager;
}

HistoryManager* MainViewModel::getHistoryManager() const {
    return m_historyManager;
}

void MainViewModel::updateStringGenerator() {
    // Update the string generator with current configuration
    m_stringGenerator->setUseUppercase(m_configManager->useUppercase());
    m_stringGenerator->setUseLowercase(m_configManager->useLowercase());
    m_stringGenerator->setUseNumbers(m_configManager->useNumbers());
    m_stringGenerator->setUseDash(m_configManager->useDash());
    m_stringGenerator->setCustomCharset(m_configManager->customCharset());
}