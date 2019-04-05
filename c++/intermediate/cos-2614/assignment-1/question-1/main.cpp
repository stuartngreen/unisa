// Semester 1: Assignment 1 Question 1
// Program to generate a username and password based on a user's full name.
#include <QtWidgets>

// Function to return a random number from 0 to the maximum range provided.
int random(int maxRange)
{
    return rand() % maxRange;
}

const int FIRST_NAME_MAX = 4;
const int USERNAME_MAX = 5;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextStream cout(stdout);

    int answer = 0;

    // Create seed for random number used in password generation.
    qsrand(QTime::currentTime().msec());

    do {
        QString input = "",
                username = "",
                password = "";
        bool ok = false;

        // Open a dialog and ask for the user's full name.
        input = QInputDialog::getText(0, "Username/Password Generator", "Type in your full name:", QLineEdit::Normal, "", &ok);

        if (ok && !input.isEmpty())
        {
            // Split the input into a list and get the index of the final item.
            QStringList names = input.split(" ");
            int lastIndex = names.length() - 1;

            // Append the first name to username (up to FIRST_NAME_MAX characters).
            if (names[0].length() < FIRST_NAME_MAX)
                username.append(names[0]);
            else
                username.append(names[0].mid(0, FIRST_NAME_MAX));

            // Handle the case where if name+surname is shorter than USERNAME_MAX, add zeroes.
            if (username.length() + names[lastIndex].length() < USERNAME_MAX)
            {
                username.append(names[lastIndex]);
                while (username.length() != USERNAME_MAX)
                {
                    username.append("0");
                }
            }
            // Otherwise append a piece of the surname of the required size.
            else
            {
                int surnameSnipSize = USERNAME_MAX - username.length();
                username.append(names[lastIndex].mid(0, surnameSnipSize));
            }

            // Make sure final username is all lowercase.
            username = username.toLower();

            // Now generate a password based on the user's original input.
            while (password.length() != 5)
            {
                // Get a random index in the range of the length of the input string,
                // and append the corresponding letter to the password (excl. spaces).
                int randomIndex = random(input.length());
                QString letter(input[randomIndex]);
                if (letter != " ")
                    password.append(letter);
            }

            // Output the username and password and ask if the user wants to generate again.
            QString response = QString("Username: %1\nPassword: %2\n\nGenerate another username/password?")
                    .arg(username)
                    .arg(password);
            answer = QMessageBox::question(0, "Generate another?", response, QMessageBox::Yes | QMessageBox::No);
        }
        else if (ok && input.isEmpty())
        {
            answer = QMessageBox::warning(0, "Oops", "Please type in a full name.", QMessageBox::Ok);
        }
        else
            answer = 0;

    } while (answer == QMessageBox::Yes || answer == QMessageBox::Ok);

    return EXIT_SUCCESS;
}
