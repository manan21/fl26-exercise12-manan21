#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:
  // Define tests here
  void initialStateIsOff();
  void clickTogglesOnAndOff();
  void multipleClicks();
};

// Implement the tests here
void TestToggleWidget::initialStateIsOff() {
  ToggleWidget w;
  QVERIFY(!w.isOn());
}

void TestToggleWidget::clickTogglesOnAndOff() {
  ToggleWidget w;
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  QVERIFY(!w.isOn());

  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(w.isOn());

  QTest::mouseClick(pb, Qt::LeftButton);
  QVERIFY(!w.isOn());
}

void TestToggleWidget::multipleClicks() {
  ToggleWidget w;
  QPushButton *pb = w.findChild<QPushButton *>();
  QVERIFY(pb != nullptr);

  for (int i = 0; i < 5; ++i) {
    QTest::mouseClick(pb, Qt::LeftButton);
    // After an odd number of clicks the light should be on
    QCOMPARE(w.isOn(), (i % 2) == 0);
  }
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
