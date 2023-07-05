//THIS CODE IS IMPROVED 
//Code Sharing: Enabling features to allow users to share code snippets with others or publish their snippets to a central repository, similar to GitHub's concept of forking and publishing projects.
//User is now prompted to decide whether they want to share/publish their codes. Depending on their choice, the snippet will either be inserted as a private snippet or shared/published to the central repository.

#include <iostream>
#include <vector>
#include <string>

// A struct called CodeSnippet is coded, which represents a code snippet in the repository
// It contains three string members: language, functionality, and code.

struct CodeSnippet {
    std::string language;
    std::string functionality;
    std::string code;

    CodeSnippet(const std::string& lang, const std::string& func, const std::string& cd)
        : language(lang), functionality(func), code(cd) {}
};

// Node represents a node in the binary search tree. 
// Each node contains a CodeSnippet object, and two pointers: 
// left and right pointing to its left and right child nodes, respectively.

struct Node {
    CodeSnippet snippet;
    Node* left;
    Node* right;

    Node(const CodeSnippet& snip)
        : snippet(snip), left(nullptr), right(nullptr) {}
};

class CodeRepository {
private:
    // root is a pointer to the root node of the binary search tree
    Node* root;

public:
    CodeRepository() : root(nullptr) {}

    void insert(const CodeSnippet& snippet) {
        root = insertRecursive(root, snippet);
    }

    void share(const CodeSnippet& snippet) {
        root = shareRecursive(root, snippet);
    }

    void remove(const CodeSnippet& snippet) {
        root = removeRecursive(root, snippet);
    }

    std::vector<CodeSnippet> search(const std::string& language, const std::string& functionality) {
        std::vector<CodeSnippet> result;
        searchRecursive(root, language, functionality, result);
        return result;
    }

    void display() {
        displayRecursive(root);
    }

private:
// The function compares the language and functionality 
// of the snippet with the current node and determines the position for insertion.
    Node* insertRecursive(Node* node, const CodeSnippet& snippet) {
        if (node == nullptr)
            return new Node(snippet);

        if (snippet.language < node->snippet.language)
            node->left = insertRecursive(node->left, snippet);
        else if (snippet.language > node->snippet.language)
            node->right = insertRecursive(node->right, snippet);
        else {
            if (snippet.functionality < node->snippet.functionality)
                node->left = insertRecursive(node->left, snippet);
            else if (snippet.functionality > node->snippet.functionality)
                node->right = insertRecursive(node->right, snippet);
            else
                std::cout << "Code snippet already exists.\n";
        }

        return node;
    }

    Node* shareRecursive(Node* node, const CodeSnippet& snippet) {
        if (node == nullptr)
            return new Node(snippet);

        if (snippet.language < node->snippet.language)
            node->left = shareRecursive(node->left, snippet);
        else if (snippet.language > node->snippet.language)
            node->right = shareRecursive(node->right, snippet);
        else {
            if (snippet.functionality < node->snippet.functionality)
                node->left = shareRecursive(node->left, snippet);
            else if (snippet.functionality > node->snippet.functionality)
                node->right = shareRecursive(node->right, snippet);
            else
                std::cout << "Code snippet already shared/published.\n";
        }
// The function recursively calls itself to insert the snippet into the appropriate subtree.
        return node;
    }

    Node* removeRecursive(Node* node, const CodeSnippet& snippet) {

// removeRecursive used to remove a code snippet from the binary search tree. 
// It takes a node parameter representing the current node being examined and a 
// snippet parameter representing the code snippet to be removed 

        if (node == nullptr)
            return node;

        if (snippet.language < node->snippet.language)
            node->left = removeRecursive(node->left, snippet);
        else if (snippet.language > node->snippet.language)
            node->right = removeRecursive(node->right, snippet);
        else {
            if (snippet.functionality < node->snippet.functionality)
                node->left = removeRecursive(node->left, snippet);
            else if (snippet.functionality > node->snippet.functionality)
                node->right = removeRecursive(node->right, snippet);
            else {
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                Node* temp = findMinNode(node->right);
                node->snippet = temp->snippet;
                node->right = removeRecursive(node->right, temp->snippet);
            }
        }

        return node;
    }

// This is a private findMin function that finds the minimum (leftmost) node in a given subtree 
// by traversing the left child pointers until a node with no left child is found.

    Node* findMinNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

// searchRecursive takes a node parameter representing the current node being examined, 
// along with the search criteria (language and functionality) 

    void searchRecursive(Node* node, const std::string& language, const std::string& functionality, std::vector<CodeSnippet>& result) {

// The function performs a search by comparing the language and functionality of the snippet 
// with the current node and traverses the appropriate subtrees to find matching snippets

        if (node == nullptr)
            return;

        if (node->snippet.language >= language && node->snippet.functionality >= functionality) {
            result.push_back(node->snippet);
            searchRecursive(node->left, language, functionality, result);
            searchRecursive(node->right, language, functionality, result);
        } else if (node->snippet.language < language)
            searchRecursive(node->right, language, functionality, result);
        else
            searchRecursive(node->left, language, functionality, result);
    }

    void displayRecursive(Node* node) {
// function displayRecursive is for displaying all the code snippets in the binary search tree
        if (node == nullptr)
            return;

        displayRecursive(node->left);
// displayRecursive used to display all the code snippets in the binary search tree.
// It performs an inorder traversal of the tree and prints the language, functionality, and code of each snippet
        std::cout << "Language: " << node->snippet.language << ", Functionality: " << node->snippet.functionality << "\n";
        std::cout << "Code:\n" << node->snippet.code << "\n";
        displayRecursive(node->right);
    }
};

// printMenu displays a different options for interacting with the code repository
void printMenu() {
    std::cout << "Welcome!! Hello!! Hola!!! \n";
    std::cout << "===== Code Repository Menu =====\n";
    std::cout << "1. Insert a code snippet\n";
    std::cout << "2. Share/Publish a code snippet\n";
    std::cout << "3. Remove a code snippet\n";
    std::cout << "4. Search for code snippets\n";
    std::cout << "5. Display all code snippets\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

// getCodeSnippetFromUser it prompts the user to enter the language, functionality, and code for a code snippet. 
// It reads the input from the user using std::getline and returns a CodeSnippet object initialized with the entered values

CodeSnippet getCodeSnippetFromUser() {
    std::cout << "Enter the language: ";
    std::string language;
    std::getline(std::cin, language);

    std::cout << "Enter the functionality: ";
    std::string functionality;
    std::getline(std::cin, functionality);

    std::cout << "Enter the code (press Enter followed by \".\" on a new line to finish):\n";
    std::string code;
    std::string line;
    while (std::getline(std::cin, line) && line != ".") {
        code += line + "\n";
    }

    return CodeSnippet(language, functionality, code);
}

int main() {
    CodeRepository repository;

    int choice = 0;
    while (choice != 6) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Do you want to share this code snippet? (y/n): ";
                char ch;
                std::cin >> ch;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (ch == 'y' || ch == 'Y') {
                    CodeSnippet snippet = getCodeSnippetFromUser();
                    repository.share(snippet);
                } else {
                    CodeSnippet snippet = getCodeSnippetFromUser();
                    repository.insert(snippet);
                }
                break;
            }
            case 2: {
                CodeSnippet snippet = getCodeSnippetFromUser();
                repository.share(snippet);
                break;
            }
            case 3: {
                CodeSnippet snippet = getCodeSnippetFromUser();
                repository.remove(snippet);
                break;
            }
            case 4: {
                std::cout << "Enter the language to search for: ";
                std::string language;
                std::getline(std::cin, language);

                std::cout << "Enter the functionality to search for: ";
                std::string functionality;
                std::getline(std::cin, functionality);

                std::vector<CodeSnippet> result = repository.search(language, functionality);
                if (result.empty()) {
                    std::cout << "No matching code snippets found.\n";
                } else {
                    std::cout << "Matching code snippets:\n";
                    for (const CodeSnippet& snippet : result) {
                        std::cout << "Language: " << snippet.language << ", Functionality: " << snippet.functionality << "\n";
                        std::cout << "Code:\n" << snippet.code << "\n";
                    }
                }
                break;
            }
            case 5: {
                std::cout << "All code snippets in the repository:\n";
                repository.display();
                break;
            }
            case 6:
                std::cout << "Exiting the program. Byiesssss!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
