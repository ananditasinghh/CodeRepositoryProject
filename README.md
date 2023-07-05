# CodeRepositoryProject



The main intention of this project organically came from GitHub itself. Being very new to GitHub, Recently when I was learning how to use GitHub, everything about forking repositories, publishing your projects, searching for the similar projects and other basic functions of GitHub, I was in parallel learning Trees and BSTs in my DSA preparation. This data structure came handy to me, and I somehow thought systematic arrangement and management of (to be honest codes was not the first thing that came in my mind) something. For this I knew how could BSTs really play a good role than LinkedLists or Arrays. And honestly, because I was learning BSTs and a direct application would have definitely helped, so I chose to go with the BST data structure. Later I did realise its benefits over other data structures due to its faster search, organised storage , efficient insertion and deletion and reduced memory overhead. Circling back to how the idea of 'CODE' arrangement came in my mind was very simple, the developers and programmers can store and organise their code snippets the way they organise their projects and applications. 

This project aims to allow the users to store, retrieve, and manage code snippets. Its my first project (DSA Project as it should be called :p) which covers the implementation of Binary Search trees data structure. Coded in c++, I've tried explaining the nitty gritty of the code with the help of comments. The most part of the project is basic level to intermediate level direct application of a Binary Search Trees. 

This project  allows users to manage and organise code snippets in a binary search tree data structure. Each code snippet is represented by a struct called CodeSnippet, which contains three string members: language, functionality, and code. The code snippets are organised based on their language and functionality in the binary search tree.

The CodeRepository class provides several functionalities to interact with the code snippets:
insert: This function allows users to insert a new code snippet into the repository. It ensures that code snippets are inserted in their appropriate positions within the binary search tree, based on language and functionality.

remove: Users can remove a specific code snippet from the repository based on its language and functionality. If the snippet is found, it will be deleted from the binary search tree.
search: Users can search for code snippets by providing a language and functionality as search criteria. The system will perform a binary search to find matching snippets and return a vector of all matching code snippets.
display: This function displays all the code snippets in the binary search tree. It performs an in-order traversal of the tree and prints the language, functionality, and code of each snippet.

The main function provides a simple command-line menu that allows users to interact with the code repository. The options available in the menu are:

1. Insert a code snippet.
2. Remove a code snippet.
3. Search for code snippets.
4. Display all code snippets.
5. Exit the program.

Users can choose the desired option by entering the corresponding number. For options 1 and 2, users will be prompted to enter the language, functionality, and code of the snippet they want to insert or remove. For option 3, users will provide the search criteria (language and functionality), and the program will display all matching code snippets. Option 4 will display all code snippets currently stored in the repository. Option 5 exits the program.

Overall, this Code Repository project provides basic functionality for managing and organizing code snippets using a binary search tree data structure, allowing developers to easily store and retrieve their code snippets based on language and functionality. 

I'm planning to work on the following aspects of this project in the near future :

- Keeping the track record of the deleted codes and inserted codes.
- Able to change or modify the already existing code and update it.
- Code Categorisation to be more efficient - to add additional meta data such as tags or categories.
- Code Sharing: Enabling features to allow users to share code snippets with others or publish their snippets to a central repository, similar to GitHub's concept of forking and publishing projects.
  (Happy to inform that this issue is fixed in the improved code)
- User interface - Although this is my first project and I have really enjoyed making it and running it, but I will agree that an output on the terminal can be improved by a more interactive and user friendly graphical interface.


