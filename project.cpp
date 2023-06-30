// Included necessary header files for input/output, vector, and string operations
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

// The function compares the language and functionality of the snippet with 
// the current node and determines the position for insertion


// insertRecursive used to insert a new code snippet into the binary search tree. 
// It takes a node parameter representing the current node being examined and a snippet parameter
// representing the new code snippet to be inserted. 

    Node* insertRecursive(Node* node, const CodeSnippet& snippet) {
        if (node == nullptr)
            return new Node(snippet);

// The function compares the language and functionality 
// of the snippet with the current node and determines the position for insertion.

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

// The function recursively calls itself to insert the snippet into the appropriate subtree.

        return node;
    }

// removeRecursive used to remove a code snippet from the binary search tree. 
// It takes a node parameter representing the current node being examined and a 
// snippet parameter representing the code snippet to be removed 

    void remove(const CodeSnippet& snippet) {
        root = removeRecursive(root, snippet);
    }

    Node* removeRecursive(Node* node, const CodeSnippet& snippet) {
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
                if (node->left == nullptr && node->right == nullptr) {
                    delete node;
                    node = nullptr;
                } else if (node->left == nullptr) {
                    Node* temp = node;
                    node = node->right;
                    delete temp;
                } else if (node->right == nullptr) {
                    Node* temp = node;
                    node = node->left;
                    delete temp;
                } else {
                    Node* successor = findMin(node->right);
                    node->snippet = successor->snippet;
                    node->right = removeRecursive(node->right, successor->snippet);
                }
            }
        }

        return node;
    }

// This is a private findMin function that finds the minimum (leftmost) node in a given subtree 
// by traversing the left child pointers until a node with no left child is found.

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

// this creates an empty vector result and calls the private searchRecursive function to perform the search

    std::vector<CodeSnippet> search(const std::string& language, const std::string& functionality) {
        std::vector<CodeSnippet> result;
        searchRecursive(root, language, functionality, result);
        return result;
    }

// searchRecursive takes a node parameter representing the current node being examined, 
// along with the search criteria (language and functionality) and a reference to the result vector


    void searchRecursive(Node* node, const std::string& language, const std::string& functionality, std::vector<CodeSnippet>& result) {
        if (node == nullptr)
            return;

// The function performs a search by comparing the language and functionality of the snippet 
// with the current node and traverses the appropriate subtrees to find matching snippets

        if (language < node->snippet.language)
            searchRecursive(node->left, language, functionality, result);
        else if (language > node->snippet.language)
            searchRecursive(node->right, language, functionality, result);
        else {
            if (functionality < node->snippet.functionality)
                searchRecursive(node->left, language, functionality, result);
            else if (functionality > node->snippet.functionality)
                searchRecursive(node->right, language, functionality, result);
            else
                result.push_back(node->snippet);

            searchRecursive(node->right, language, functionality, result);
        }
    }

// function displayRecursive is for displaying all the code snippets in the binary search tree

    void display() {
        displayRecursive(root);
    }

// displayRecursive used to display all the code snippets in the binary search tree.
// It performs an inorder traversal of the tree and prints the language, functionality, and code of each snippet

    void displayRecursive(Node* node) {
        if (node != nullptr) {
            displayRecursive(node->left);
            std::cout << "Language: " << node->snippet.language << "\n";
            std::cout << "Functionality: " << node->snippet.functionality << "\n";
            std::cout << "Code: " << node->snippet.code << "\n";
            std::cout << "-------------------------\n";
            displayRecursive(node->right);
        }
    }
};

// printMenu displays a different options for interacting with the code repository

void printMenu() {
    std::cout << "====== Code Repository Menu ======\n";
    std::cout << "1. Insert a code snippet\n";
    std::cout << "2. Remove a code snippet\n";
    std::cout << "3. Search for code snippets\n";
    std::cout << "4. Display all code snippets\n";
    std::cout << "5. Exit\n";
    std::cout << "===================================\n";
    std::cout << "Enter your choice: ";
}

// getCodeSnippetFromUser it prompts the user to enter the language, functionality, and code for a code snippet. 
// It reads the input from the user using std::getline and returns a CodeSnippet object initialized with the entered values

CodeSnippet getCodeSnippetFromUser() {
    std::string language, functionality, code;
    std::cout << "Enter language: ";
    std::getline(std::cin >> std::ws, language);
    std::cout << "Enter functionality: ";
    std::getline(std::cin >> std::ws, functionality);
    std::cout << "Enter code: ";
    std::getline(std::cin >> std::ws, code);
    return CodeSnippet(language, functionality, code);
}

// displayCodeSnippets takes a vector of code snippets as input and displays 
// the details of each snippet and if no snippets are found, it displays a message reagrding that too

void displayCodeSnippets(const std::vector<CodeSnippet>& snippets) {
    if (snippets.empty()) {
        std::cout << "No matching code snippets found.\n";
    } else {
        std::cout << "Matching code snippets:\n";
        for (const auto& snippet : snippets) {
            std::cout << "Language: " << snippet.language << "\n";
            std::cout << "Functionality: " << snippet.functionality << "\n";
            std::cout << "Code: " << snippet.code << "\n";
            std::cout << "-------------------------\n";
        }
    }
}

// The user can choose different options (1-5) to insert a code snippet,
// remove a code snippet, search for code snippets, display all code snippets, or exit the program

int main() {
    CodeRepository repository;

    int choice = 0;
    while (choice != 5) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                CodeSnippet snippet = getCodeSnippetFromUser();
                repository.insert(snippet);
                std::cout << "Code snippet inserted successfully.\n";
                break;
            }
            case 2: {
                CodeSnippet snippet = getCodeSnippetFromUser();
                repository.remove(snippet);
                std::cout << "Code snippet removed successfully.\n";
                break;
            }
            case 3: {
                std::string language, functionality;
                std::cout << "Enter language to search: ";
                std::getline(std::cin >> std::ws, language);
                std::cout << "Enter functionality to search: ";
                std::getline(std::cin >> std::ws, functionality);

                std::vector<CodeSnippet> snippets = repository.search(language, functionality);
                displayCodeSnippets(snippets);
                break;
            }
            case 4: {
                std::cout << "All code snippets:\n";
                repository.display();
                break;
            }
            case 5: {
                std::cout << "Exiting the program.\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. \n";
                break;
            }
        }

        std::cout << "\n";
    }

    return 0;
}

