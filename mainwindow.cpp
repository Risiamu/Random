#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , m_viewModel(new MainViewModel(this)) {
    
    setupUi();
    connectSignalsAndSlots();
    
    // Set window title and size
    setWindowTitle("Random String Generator");
    resize(600, 500);
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUi() {
    // Create central widget and main layout
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);
    m_mainLayout = new QVBoxLayout(m_centralWidget);
    
    // Create generated string display
    QHBoxLayout* generatedStringLayout = new QHBoxLayout();
    m_generatedStringEdit = new QLineEdit(this);
    m_generatedStringEdit->setReadOnly(true);
    m_generatedStringEdit->setPlaceholderText("Generated string will appear here");
    m_generateButton = new QPushButton("Generate", this);
    m_copyButton = new QPushButton("Copy", this);
    
    generatedStringLayout->addWidget(m_generatedStringEdit);
    generatedStringLayout->addWidget(m_generateButton);
    generatedStringLayout->addWidget(m_copyButton);
    
    m_mainLayout->addLayout(generatedStringLayout);
    
    // Create configuration group box
    m_configGroupBox = new QGroupBox("Configuration", this);
    m_configLayout = new QGridLayout(m_configGroupBox);
    
    m_uppercaseCheckBox = new QCheckBox("Include Uppercase (A-Z)", this);
    m_lowercaseCheckBox = new QCheckBox("Include Lowercase (a-z)", this);
    m_numbersCheckBox = new QCheckBox("Include Numbers (0-9)", this);
    m_dashCheckBox = new QCheckBox("Include Dash (-)", this);
    
    m_uppercaseCheckBox->setChecked(true);
    m_lowercaseCheckBox->setChecked(true);
    m_numbersCheckBox->setChecked(true);
    m_dashCheckBox->setChecked(true);
    
    m_configLayout->addWidget(m_uppercaseCheckBox, 0, 0);
    m_configLayout->addWidget(m_lowercaseCheckBox, 0, 1);
    m_configLayout->addWidget(m_numbersCheckBox, 1, 0);
    m_configLayout->addWidget(m_dashCheckBox, 1, 1);
    
    QLabel* customCharsetLabel = new QLabel("Custom Character Set:", this);
    m_customCharsetEdit = new QLineEdit(this);
    m_customCharsetEdit->setPlaceholderText("Leave empty to use checkboxes above");
    
    m_configLayout->addWidget(customCharsetLabel, 2, 0);
    m_configLayout->addWidget(m_customCharsetEdit, 2, 1);
    
    m_lengthLabel = new QLabel("String Length:", this);
    m_lengthSpinBox = new QSpinBox(this);
    m_lengthSpinBox->setRange(1, 100);
    m_lengthSpinBox->setValue(10);
    
    m_configLayout->addWidget(m_lengthLabel, 3, 0);
    m_configLayout->addWidget(m_lengthSpinBox, 3, 1);
    
    m_mainLayout->addWidget(m_configGroupBox);
    
    // Create history group box
    m_historyGroupBox = new QGroupBox("History", this);
    m_historyLayout = new QVBoxLayout(m_historyGroupBox);
    
    m_historyListWidget = new QListWidget(this);
    m_clearHistoryButton = new QPushButton("Clear History", this);
    
    m_historyLayout->addWidget(m_historyListWidget);
    m_historyLayout->addWidget(m_clearHistoryButton);
    
    m_mainLayout->addWidget(m_historyGroupBox);
}

void MainWindow::connectSignalsAndSlots() {
    // Connect UI signals to slots
    connect(m_generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateClicked);
    connect(m_copyButton, &QPushButton::clicked, this, &MainWindow::onCopyClicked);
    connect(m_clearHistoryButton, &QPushButton::clicked, this, &MainWindow::onClearHistoryClicked);
    
    // Connect configuration changes
    connect(m_uppercaseCheckBox, &QCheckBox::toggled, this, &MainWindow::updateConfigFromUi);
    connect(m_lowercaseCheckBox, &QCheckBox::toggled, this, &MainWindow::updateConfigFromUi);
    connect(m_numbersCheckBox, &QCheckBox::toggled, this, &MainWindow::updateConfigFromUi);
    connect(m_dashCheckBox, &QCheckBox::toggled, this, &MainWindow::updateConfigFromUi);
    connect(m_customCharsetEdit, &QLineEdit::textChanged, this, &MainWindow::updateConfigFromUi);
    connect(m_lengthSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateConfigFromUi);
    
    // Connect ViewModel signals to slots
    connect(m_viewModel, &MainViewModel::stringGenerated, this, &MainWindow::onStringGenerated);
    connect(m_viewModel, &MainViewModel::stringCopied, this, &MainWindow::onStringCopied);
    connect(m_viewModel->getHistoryManager(), &HistoryManager::historyChanged, this, &MainWindow::onHistoryChanged);
    
    // Connect history list item double click to copy
    connect(m_historyListWidget, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem* item) {
        if (item) {
            m_viewModel->copyToClipboard(item->text());
        }
    });
}

void MainWindow::updateConfigFromUi() {
    ConfigManager* configManager = m_viewModel->getConfigManager();
    
    configManager->setUseUppercase(m_uppercaseCheckBox->isChecked());
    configManager->setUseLowercase(m_lowercaseCheckBox->isChecked());
    configManager->setUseNumbers(m_numbersCheckBox->isChecked());
    configManager->setUseDash(m_dashCheckBox->isChecked());
    configManager->setCustomCharset(m_customCharsetEdit->text());
    configManager->setStringLength(m_lengthSpinBox->value());
}

void MainWindow::onGenerateClicked() {
    m_viewModel->generateString();
}

void MainWindow::onCopyClicked() {
    m_viewModel->copyToClipboard(m_generatedStringEdit->text());
}

void MainWindow::onClearHistoryClicked() {
    m_viewModel->clearHistory();
}

void MainWindow::onStringGenerated(const QString& str) {
    m_generatedStringEdit->setText(str);
}

void MainWindow::onStringCopied(const QString& str) {
    QMessageBox::information(this, "Copied", "String copied to clipboard: " + str);
}

void MainWindow::onHistoryChanged(const QStringList& history) {
    m_historyListWidget->clear();
    m_historyListWidget->addItems(history);
}

void MainWindow::onConfigChanged() {
    // Update UI from config if needed
}