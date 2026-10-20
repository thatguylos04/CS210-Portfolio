# CS210 Portfolio: Corner Grocer Item Tracker
## Summarize the project and what problem it was solving.
The Corner Grocer needed a way to make sense of the purchase records they generate every day so they could rearrange their produce section around what customers actually buy. My program reads the day's records from a text file, counts how many times each item was purchased, and gives the user a menu to look up a single item, see every item with its count, or view the counts as a text histogram. It also saves all of the counts to a backup file called frequency.dat as soon as it starts, with nothing needed from the user.

## What did you do particularly well?
I think the structure is the strongest part. Everything is built around one class, GroceryTracker, which keeps its data private and only makes public the actions the menu needs. Using a map for the counts kept the logic simple, since one line handles both new items and repeats, and the map keeps everything in alphabetical order on its own. I also added input validation so the menu doesn't break if someone types a letter or a number outside 1 to 4, and the item search ignores capitalization and returns 0 for anything that wasn't sold.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
- **Faster lookups:** Right now the search loops through the whole map and compares lowercase versions of each name. Storing every name in lowercase when the file loads would let me use the map's own find function, which is much faster on a large file.
- **Safer input handling:** The program trusts that the input file is clean. Checking for blank lines, numbers, or unexpected characters would make it more secure and more reliable with real store data.
- **Better histogram:** Scaling or capping the bars would keep a very popular item from printing a line too long for the screen.
- **More flexibility:** Letting the user load a different day's file without restarting would make it more useful for the store.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
Honestly, the hardest parts were more about the environment than the C++ itself. The program couldn't find the input file until I understood that Visual Studio runs the program from the project folder, so I created the text file inside Visual Studio to make sure it landed in the right place. I also ran the program in debug mode with F5 instead of Ctrl+F5 and had to figure out why the console kept slipping behind Visual Studio. In the code, getting the menu validation right took some thought, because a bad entry can send cin into an endless loop unless you clear the error state and throw away the bad input.

For support, I relied on the zyBooks sections on classes, maps, and file input and output. I used YouTube videos and cppreference.com.

## What skills from this project will be particularly transferable to other projects or coursework?
- Designing a class with a clear split between public and private sections
- Choosing the right data structure for the job, like a map for counting
- Reading from and writing to files
- Validating user input so a program handles bad data instead of crashing
- Testing each feature on its own before calling the program done

These carry over to almost any program, especially anything that processes data.

## How did you make this program maintainable, readable, and adaptable?
- **Organized files:** The class is split into GroceryTracker.h and GroceryTracker.cpp, which keeps main.cpp short and focused on the menu.
- **Clear naming and comments:** Every function and key step has a comment, and names like itemFrequencies and GetItemFrequency say exactly what they do.
- **Easy to change:** Both file names are constants at the top of main.cpp, so switching files means editing one line.
- **Protected data:** Functions that only read data are marked const, so the compiler stops them from changing the counts by accident.
- **Easy to extend:** Each menu option is its own method, so adding a feature means writing one method and adding one menu case.
