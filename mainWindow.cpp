// mainwindow.cpp
   #include "mainwindow.h"
   #include <QMessageBox>

   MainWindow::MainWindow(QWidget *parent)
       : QMainWindow(parent), game("cardData.json")
   {
       centralWidget = new QWidget(this);
       setCentralWidget(centralWidget);

       mainLayout = new QVBoxLayout(centralWidget);
       handLayout = new QHBoxLayout();
       fieldLayout = new QHBoxLayout();

       drawButton = new QPushButton("Draw Card", this);
       endTurnButton = new QPushButton("End Turn", this);
       deckSizeLabel = new QLabel(this);
       turnLabel = new QLabel(this);

       mainLayout->addWidget(turnLabel);
       mainLayout->addLayout(fieldLayout);
       mainLayout->addLayout(handLayout);
       mainLayout->addWidget(drawButton);
       mainLayout->addWidget(endTurnButton);
       mainLayout->addWidget(deckSizeLabel);

       connect(drawButton, &QPushButton::clicked, this, &MainWindow::drawCard);
       connect(endTurnButton, &QPushButton::clicked, this, &MainWindow::endTurn);

       updateUI();
   }

   void MainWindow::drawCard()
   {
       if (game.drawCard()) {
           updateUI();
       } else {
           QMessageBox::warning(this, "Warning", "No more cards in the deck!");
       }
   }

   void MainWindow::playCard()
   {
       CardWidget *cardWidget = qobject_cast<CardWidget*>(sender());
       if (cardWidget) {
           int index = handLayout->indexOf(cardWidget);
           if (index != -1) {
               game.playCard(index);
               updateUI();
           }
       }
   }

   void MainWindow::endTurn()
   {
       game.endTurn();
       updateUI();
   }

   void MainWindow::updateUI()
   {
       // Clear existing layouts
       QLayoutItem *child;
       while ((child = handLayout->takeAt(0)) != nullptr) {
           delete child->widget();
           delete child;
       }
       while ((child = fieldLayout->takeAt(0)) != nullptr) {
           delete child->widget();
           delete child;
       }

       // Update hand
       for (const auto &card : game.getHand()) {
           CardWidget *cardWidget = new CardWidget(card);
           connect(cardWidget, &CardWidget::clicked, this, &MainWindow::playCard);
           handLayout->addWidget(cardWidget);
       }

       // Update field
       for (const auto &card : game.getField()) {
           CardWidget *cardWidget = new CardWidget(card);
           fieldLayout->addWidget(cardWidget);
       }

       // Update labels
       deckSizeLabel->setText(QString("Cards in deck: %1").arg(game.getDeckSize()));
       turnLabel->setText(QString("Turn: %1").arg(game.isPlayerTurn() ? "Player" : "Computer"));

       // Enable/disable buttons
       drawButton->setEnabled(game.isPlayerTurn());
       endTurnButton->setEnabled(game.isPlayerTurn());
   }