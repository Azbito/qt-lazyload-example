#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // starts at 1
    startIndex = 1;
    // it will load from 10 to 10 per button press
    batchSize = 10;

    // configuring scroll area in order to be resizable
    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);

    // creates a scrollarea widget in the window
    QWidget *scrollWidget = new QWidget(scrollArea);
    scrollLayout = new QVBoxLayout(scrollWidget);
    scrollWidget->setLayout(scrollLayout);
    scrollArea->setWidget(scrollWidget);

    // creates a button called Load More
    loadButton = new QPushButton("Load More", this);
    // connects this button with the function loadMore()
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::loadMore);

    // sets the created widgets into the mainLayout
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->centralwidget);
    mainLayout->addWidget(scrollArea);
    mainLayout->addWidget(loadButton);

    // initialises by loading it from 1 to 10
    loadMore();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadMore()
{
    // for each start index to batch size
    for (int i = startIndex; i < startIndex + batchSize; ++i) {
        // creates a label with the text "Lizard" with the number of the current index
        QLabel *label = new QLabel(QString("Lizard %1").arg(i));
        // add the widget named label into scrollLayout container
        scrollLayout->addWidget(label);
    }

    // update the index to point to the next batch of items to be loaded
    startIndex += batchSize;
}

// And now you've got your lazy load c:
