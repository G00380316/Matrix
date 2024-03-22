---
layout: post
title: A Digital-Rain Project in Modern C++
tags: cpp coding project
author: Enoch Abiodun
---

Within this blog post, You and I will explore in depth and detail involved in coding a Digital Rain Matrix using Cpp (C++). We’ll discuss the necessary guidelines, outline our approach on how we ourselves could code such an application and then provide step-by-step analysis on how I managed to do so for my Final year Cpp mini-Project.

## ***Problem Statement:***

Usually, problems would be the last thing as programmers or anyone in general would like to face. In this application I believe that going head on at the blatant blockers that will hinder you in the future is the only way to go. So, like first I would say is printing Characters vertically requires efficient processing of console output to mimic the dynamic effect of characters falling from the top of the console to the bottom. To create a visually appealing animation, random character generation may even be implemented with varying speeds also to make the application more visually appealing. Second, creating a console-based digital rain matrix requires managing the complexity of really managing were to print characters on the console there are many ways this action could be done. One...using a library that allows you to mess with the cursor position or turning the whole console to a grid the possibilities are endless but that’s what I believe makes it more challenging. Balancing performance and aesthetics become increasingly important, especially when using larger grids and faster frame rates. Finally, creating an interactive version of the digital rain matrix adds new complications such as user input and real-time updates, but maintains a simple interface for manipulating animation parameters. Overcoming these obstacles requires care when sitting then and thinking about Algorithms, data structures like vectors, arrays, and user interface design all must be considered to provide users with a seamless and engaging experience that makes it as entertaining and eye-catching as the original Digital Rain Matrix from the movie “The Matrix”.

## ***Background Information:***

The primal objective of this project was to have solid foundations when it comes to the world of “Objected Orientated Programming”, better known as OOP. As this project and this blog was made for educational purposes it is vital we are accustomed to Industrial Standards such as OOP. In the rest of this paragraph, I will be explaining some of the basic concepts involved in a Digital Rain cpp project and keeping to OOP whilst programming this project. File structure, the initial step on producing clean code in Cpp is having “headers” and “cpp” files headers having the file association or extension .h and .cpp. This allows to separate our classes from our objects so we can formulate a clear structure and reduce complexity in such an already complex project. What goes in the header and cpp file you may ask? Well, think of it like a title of a page that gives you an idea of what is going to be in the rest of page content. It is same concept headers provides cpp files with context the header file is where data members and functions/methods are initially defined, and these can either private or public to inherit some data protection. Cpp on the other hand is where this functions and data variables are used to create functionality. A header file is referred to in a cpp by the line #include “(directory of the file)”. To get further information about OOP, and more sub concepts I would like to suggest reading the book “C++ Primer” by Stanley B. Lippman, Josee Lajoie and Babara E. Moo. In this book you can learn more about all the solid foundations that can be learned when coding in Cpp. Furthermore, I believe Inheritance Is vital when we talk about splitting the project into different cpp files. Inheritance basically allows other classes access to another classes functions/methods this is how we integrate to make one whole project. Why this is important because it allows us to test different functionality of different aspects of the project on its own without must run other parts or the finished project. Another basic concept that you would have to consider is the actual Digital Rain Effect the can be various of ways and styling when it comes to displaying falling characters, headings you would most likely think about would be Animation, Printing Systems (that manages the creation, update and rendering of characters), Randomisation that can be achieved by using functions in the “<random>” library, Colour and Styling and Performance Optimisation that can be crucial when dealing with real-time graphics, this can be done by simply using efficient data structures such as vectors and really having really tight Algorithmic, logical, Numerical and Symbolic Computations.

## ***Solution Approach and Implementation:***

Here I will talk about more of how I came up with an approach to coding a Digital Rain project. So, the first class I began making was a class that generates random character.

*1. Character Set Initialization:*

The Random Generator class begins by initializing a set of characters to choose from. In our implementation, we've included uppercase letters (A-Z), lowercase letters (a-z), digits (0-9), and a selection of special characters. By populating a vector named characters with this diverse set of characters, we ensure that our random generator can produce a wide range of outputs, adding richness to our digital rain effect.

`

RandomGenerator::RandomGenerator() {

    for (char c = 'A'; c <= 'Z'; ++c) {
        characters.push_back(c);
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        characters.push_back(c);
    }
    for (char c = '0'; c <= '9'; ++c) {
        characters.push_back(c);
    }
    for (char c = '!'; c <= '/'; ++c) {
        characters.push_back(c);
    }
    for (char c = ':'; c <= '@'; ++c) {
        characters.push_back(c);
    }
    for (char c = '['; c <= '`'; ++c) {
        characters.push_back(c);
    }
    for (char c = '{'; c <= '~'; ++c) {
        characters.push_back(c);
    }
}

`
 
*2. Generating Random Characters:*

The core functionality of the RandomGenerator class lies in the generateRandomCharacters method. This method takes an integer parameter numCharacters, indicating the number of random characters to generate. Inside the method, we use the C++ <random> library to create a random number generator (std::mt19937) and a uniform distribution (std::uniform_int_distribution) to select random indices from the characters vector. By iterating numCharacters times, we randomly select characters from the characters vector based on the generated indices and store them in a vector named randomCharacters. Finally, we return this vector containing the randomly generated characters.
 Colour plays a significant role in enhancing the visual appeal of applications, especially when creating dynamic and immersive experiences like digital rain simulations. In this blog post, we'll delve into the implementation of a C++ class called ColourChanger, which is designed to add colour-changing effects to our digital rain matrix. By understanding this code, you'll gain insights into how to incorporate colour manipulation into your own projects, elevating their aesthetics and user engagement.

`

std::vector<char> RandomGenerator::generateRandomCharacters(int numCharacters) {
    std::vector<char> randomCharacters;

    // Generate random indices to pick characters from the characters vector
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, characters.size() - 1);

    for (int i = 0; i < numCharacters; ++i) {
        int randomIndex = dis(gen);
        randomCharacters.push_back(characters[randomIndex]);
    }

    return randomCharacters;
}

`

*3. Initialization and Control:*

The ColourChanger class begins with a constructor that initializes a Boolean variable isRunning to false, indicating that the colour-changing process is not yet active. The startChangingColours method controls the colour-changing process by entering a loop while isRunning is true. Within this loop, calls to the change Colour method are made successively with different ANSI escape codes representing various colours, creating a cyclic colour-changing effect. By toggling isRunning appropriately, we can start or stop the colour-changing process as needed.

`

ColourChanger::ColourChanger() : isRunning(false) {}

// ANSI escape code for colorchange
void ColourChanger::startChangingColours() {
    if (isRunning) {
        return;
    }
    isRunning = true;
    while (isRunning) {
        changeColour("\033[32m"); //green
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[36m"); //cyan
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[33m"); //yellow
        //std::this_thread::sleep_for(std::chrono::seconds(5));
        changeColour("\033[35m"); //Magenta
        //std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

`
 
*4. Colour Manipulation:*

The changeColour method is responsible for changing the foreground colour of text in the console. It accepts a string parameter colourCode, which represents the ANSI escape code for the desired colour. By outputting this code to the console using std::cout, we can change the colour of subsequent text accordingly. Similarly, the changeBackgroundColour method can be implemented to change the background colour of text, providing further customization options for enhancing visual effects.

`

void ColourChanger::changeColour(const std::string& colorCode) {
    std::cout << colorCode;
}

void ColourChanger::changeBackgroundColour(const std::string& colorCode) {
    std::cout << colorCode;
}

`

In the realm of programming, creating captivating visual effects can greatly enhance user experiences. One such effect is the mesmerizing digital rain matrix, reminiscent of scenes from movies like "The Matrix." In this blog post, we'll explore the implementation of a C++ class called Digital Rain, which generates a digital rain matrix effect in the console. By understanding this code, you'll gain insights into how to simulate falling characters, manage console output, and incorporate multithreading for dynamic colour-changing effects.

 <img src="https://github.com/G00380316/Matrix/blob/302b39313411abcaaaf32fe9a1f335ff3e88e0bc/docs/assets/images/Picture5.png" width="1200" height="400">
 
*5. Initialization and Threading:*
   
The Digital Rain class begins by initializing its components, including instances of Colour Changer and Random Generator. To achieve dynamic colour changes, a separate thread is launched to execute the startChangingColours method of the Colour Changer class. This ensures that colour changes occur independently of the main execution flow, enhancing the visual appeal of the digital rain matrix.

`

DigitalRain::DigitalRain() {}

void DigitalRain::startGenerating() {
    std::thread colourThread(&ColourChanger::startChangingColours, &colourChanger); // Starts a separate thread for changing colours
    std::vector<char> randomCharacters;
    std::vector<char> charactersBuffer;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    //To be continued
    
`
 
*6. Character Generation and Console Output:*

Within the main loop of the startGenerating method, random characters are generated using the RandomGenerator class. These characters are then displayed in the console, simulating the falling raindrops of the digital matrix. The position of each character is managed to create the illusion of movement, while checks ensure that the console window boundaries are respected. If the bottom of the console window is reached, the screen is cleared to maintain the continuous flow of the digital rain matrix.

`
   //Continued
while (true) {
        mtx.lock();
        randomCharacters = randomGenerator.generateRandomCharacters(5);
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        int numSpaces = rand() % csbi.dwSize.X;
        mtx.unlock();

        for (int i = 0; i < numSpaces; ++i) {
            mtx.lock();
            std::cout << ' ';
            mtx.unlock();
        }

        for (const auto& character : randomCharacters) {
            charactersBuffer.push_back(character);
        }
        if (charactersBuffer.size() == 5) {
            for (const auto& character : charactersBuffer) {
                mtx.lock();
                SetCursorPosition();
                std::cout << character;
                std::cout.flush();
                //csbi.dwCursorPosition.X - 1;
                mtx.unlock();
            }

            // Check if the console window has reached the bottom
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            if (csbi.dwCursorPosition.Y >= csbi.dwSize.Y - 1) {
                mtx.lock();
                COORD coord = { 0, 0 };
                DWORD written;
                FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &written);
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                mtx.unlock();
            }
            charactersBuffer.clear();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(750)); // Sleep for 1 second normally but to see different patterns change to you liking
    }

    colourThread.join(); // Wait for the colour changing thread to finish
}

`

*Multithreading and Dynamic Colour Changes:*

To add dynamic colour-changing effects to the digital rain matrix, a separate thread executes the `startChangingColours` method of the `ColourChanger` class. This method cyclically changes the colour of the text displayed in the console, enhancing the visual appeal and depth of the digital rain effect. Multithreading ensures that colour changes occur concurrently with character generation and display, resulting in a seamless and dynamic simulation.
Testing and Validation:

While testing and validating the digital rain project, I carefully evaluated the functionality of each component to ensure reliability and accuracy in a variety of conditions. In the RandomGenerator class, I rigorously examine the correctness and randomness of the generated characters, ensuring even distribution and compliance within specific limits. In the ColourChanger class, I visually observed the colour change function and observed the independent execution of the colour change thread using debug tools that confirmed dynamic and synchronized colour transitions. I also visually checked the console output in the DigitalRain class to confirm character creation, scrolling behaviour and dynamic colour changes, ensuring the overall strength of the project, and providing users with an immersive and visually intriguing experience.

*Performance Optimisation:*

Some of the Performance Optimisation I carried out towards the climax would include adding mutexes to protect resources. Using a buffer to print out characters instead of just allowing a stream of characters to be printed this gives time for each thread to store up characters before they are printed therefore using less resources.

*Conclusion:*

Finally, developing a sophisticated rain extension using object-oriented programming in C++ has enabled us to create a secure, adaptable, and viable solution. By organising our code into classes and objects, we've standardised the behaviour of our advanced rain framework, making it easier to obtain and expand. We've achieved adaptability in dealing with different aspects of the project, such as character creation, thread creation, and resource protection, via careful consideration and research. Furthermore, by adhering to OOP concepts such as inheritance, headers we’ve advanced code reusability and isolation, allowing for future upgrades and changes. Leveraging OOP in C++ has not only allowed us to implement the digital rain matrix efficiently but has help cultivate a great foundation in OOP C++, clearing the way for building more sophisticated and vigorous applications within the future. 

## ***Additional Resources:***

For further reading on object orientated programming and information I believe to help you created your own Digital Rain project, check out the following resources:
- [Object-oriented Programming - Wikipedia] ( [Object-oriented programming](https://en.wikipedia.org/wiki/Object-oriented_programming) - Wikipedia)
- [Vector in C++ STL- GeeksforGeeks] ( [Vector in C++ STL](https://www.geeksforgeeks.org/vector-in-cpp-stl/) - GeeksforGeeks)
- [Thread- Cppreference] ( [std::thread](https://en.cppreference.com/w/cpp/thread/thread) - cppreference.com) 
- [Character colour- Quora] ( [In C++, how do I print out text at different font colors on the terminal?](https://www.quora.com/In-C-how-do-I-print-out-text-at-different-font-colors-on-the-terminal#:~:text=Colors%20for%20text%20are%20represented,red%20text%20%5Ce%5B0m%22) - Quora)

*Enoch Abiodun is a software engineer with a passion for algorithms and problem-solving. He enjoys sharing his knowledge and experiences through blogging and open-source contributions.
G00380316/Matrix (github.com)*

***If you found this blog post helpful, consider subscribing to our newsletter for more coding tutorials and tips. Don't forget to share this post with your friends and colleagues who might also benefit from it!***

