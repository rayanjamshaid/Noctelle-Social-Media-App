# Noctelle
#  Terminal-Based Social Media App (C++ OOP Project)

This is a terminal-based social media simulation built in **C++**, applying core **Object-Oriented Programming (OOP)** principles such as **abstraction**, **inheritance**, **composition**, **aggregation**, and the use of **virtual functions**.

The project simulates a basic social media application where users can interact through posts and comments. The goal of the project is to explore and apply C++ OOP design in a real-world-like system, using self-implemented data structures and strict OOP modeling.

---

##  Features

- Create and manage **users**
- Post and manage **posts**
- Add and view **comments** on posts
- Handle **dates and activity logs**
- Self made **custom dynamic array class** (to mimic the functionality of `std::vector`)
- Fully terminal-based user interface

---

##  Technologies & Concepts Used

- **C++**
- **OOP Principles**:
  - **Abstraction**: Abstract base classes for modular design
  - **Inheritance & Virtual Classes**: Polymorphic behavior between base and derived types
  - **Composition & Aggregation**: Real-world relationships between objects like `User`, `Post`, `Comment`, and `Date`
- **Custom Data Structures**:
  - Self-implemented `C_Array` and `Array` (custom dynamic array)
- **Modular Codebase**:
  - Each class/component in separate `.cpp/.h` files
- **Makefile**:
  - Simplified build process with `make`

---

##  Project Structure

```bash
.
├── Main.cpp           
├── App.cpp         
├── User.cpp  
├── Post.cpp  
├── Comment.cpp   
├── Date.cpp     
├── Activity.cpp       
├── Pages.cpp        
├── Helper.cpp          
├── C_Array.cpp        
├── Memory.cpp         
├── Makefile           
└── README.md          
 ```

 ##  Prerequisites
 - **g++ Compiler**
 - **A terminal or shell (Linux, macOS, or Git Bash for Windows)**

 ##  Compile
 ```bash
 make
 ```
 Or you can do this
 ```bash
 make build
 ```

 ## Run
  ```bash
 make run
 ```
 Or you can do this
 ```bash
 ./main
 ```

 *You may have to switch between* `./main` *or* `./main.exe` *depending on your system or terminal (powershell, bash, WSL).*

## Learning Outcomes
#### Through this project, I reinforced:
- Practical understanding of OOP in a real-world context
- Building custom data structures in C++
- Managing relationships between complex objects
- Modular code organization and build systems using Makefiles
- Clear separation of logic, interface, and data


## Future Improvements
- Add persistent storage (e.g., file I/O or SQLite)
- Improve UI with better formatting or a minimal GUI
- Add unit tests for components like C_Array and User
- Remove the bugs which I have been trying to ignore

## License
 This project is open-source and free to use under the MIT License.

## Author
 Author
 
 Rayan Jamshaid

 C++ Developer

 