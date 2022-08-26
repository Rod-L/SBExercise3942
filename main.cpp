#include <QApplication>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;

    QHBoxLayout layout(&window);

    QLineEdit text("", &window);
    text.resize(200, 100);
    layout.addWidget(&text);

    QLabel result(&window);
    result.setText("Enter phone number");
    result.setStyleSheet("color: gray");
    layout.addWidget(&result);

    QRegularExpression regexp("^[+][0-9]{11}$");

    text.connect(&text, &text.textChanged, [&text, &result, &regexp](){
        auto phoneNumber = text.text();
        if (phoneNumber.isEmpty()) {
            result.setText("Enter phone number");
            result.setStyleSheet("color: gray");
        } else if (regexp.match(phoneNumber).hasMatch()) {
            result.setText("Correct");
            result.setStyleSheet("color: green");
        } else {
            result.setText("Wrong");
            result.setStyleSheet("color: red");
        }
    });

    window.show();
    return QApplication::exec();
}
