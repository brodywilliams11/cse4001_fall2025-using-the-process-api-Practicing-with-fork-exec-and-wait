# Assignment: Practicing the Process API
Practicing with fork, exec, wait. 

### Overview

In this assignment, you will practice using the Process API to create processes and run programs under Linux. The goal is to gain hands-on experience with system calls related to process management. Specifically, you will practice using the unix process API functions 'fork()', 'exec()', 'wait()', and 'exit()'. 

⚠️ Note: This is not an OS/161 assignment. You will complete it directly on Linux. 

Use the Linux in your CSE4001 container. If you are using macOS, you may use the Terminal (you may need to install development tools with C/C++ compilers). 

**Reference Reading**: Arpaci-Dusseau, *Operating Systems: Three Easy Pieces*, Chapter 5 (Process API Basics)
 👉 [Chapter 5 PDF](http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf)

---

### **Steps to Complete the Assignment**

1. **Accept the GitHub Classroom Invitation**
    [GitHub Link](https://classroom.github.com/a/FZh4BrQG)
2. **Set up your Repository**
   - Clone the assignment repository.
3. **Study the Reference Materials**
   - Read **Chapter 5**.
   - Download and explore the sample programs from the textbook repository:
      [OSTEP CPU API Code](https://github.com/remzi-arpacidusseau/ostep-code/tree/master/cpu-api).
4. **Write Your Programs**
   - Adapt the provided example code to answer the assignment questions.
   - Each program should be clear, well-commented, and compile/run correctly.
   - Add your solution source code to the repository.

5. **Prepare Your Report**
   - Answer the questions in the README.md file. You must edit the README.md file and not create another file with the answers. 
   - For each question:
     - Include your **code**.
     - Provide your **answer/explanation**.
6. **Submit Your Work via GitHub**
   - Push both your **program code** to your assignment repository.
   - This push will serve as your submission.
   - Make sure all files, answers, and screenshots are uploaded and rendered properly.








---
### Questions
1. Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process? What happens to the variable when both the child and parent change the value of x?

<img width="1240" height="557" alt="Screenshot 2025-09-24 223737" src="https://github.com/user-attachments/assets/5f89a8a8-a8f8-4b9f-bd92-02443ac3c367" />
```cpp
<img width="1240" height="557" alt="Screenshot 2025-09-24 223737" src="https://github.com/user-attachments/assets/5f89a8a8-a8f8-4b9f-bd92-02443ac3c367" />
The child and parent each get their own copy of x. If it is changed in one process, it doesn't affect the other. 
```


2. Write a program that opens a file (with the `open()` system call) and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor returned by `open()`? What happens when they are writing to the file concurrently, i.e., at the same time?

```cpp
<img width="1239" height="564" alt="Screenshot 2025-09-24 223755" src="https://github.com/user-attachments/assets/181a18d4-331c-4cd7-9ef9-a6241a48b795" />
Both parent and child share the same file descriptor. If they write at the same time, the <img width="1250" height="571" alt="Screenshot 2025-09-24 223814" src="https://github.com/user-attachments/assets/9cfbc520-7070-4a39-80f1-8d5ec0190471" />
output might interleave. 
```

3. Write another program using `fork()`.The child process should print “hello”; the parent process should print “goodbye”. You should try to ensure that the child process always prints first; can you do this without calling `wait()` in the parent?

```cpp
![Uploading Screenshot 2025-09-24 223814.png…]()
The parent and child may print in any order but if you use sleep(), the child will print first.
```


4. Write a program that calls `fork()` and then calls some form of `exec()` to run the program `/bin/ls`. See if you can try all of the variants of `exec()`, including (on Linux) `execl()`, `execle()`, `execlp()`, `execv()`, `execvp()`, and `execvpe()`. Why do you think there are so many variants of the same basic call?

```cpp
<img width="1251" height="577" alt="Screenshot 2025-09-24 223832" src="https://github.com/user-attachments/assets/d2944deb-ed16-4ea7-9439-7d5d20c440f9" />
exec() replaces the current process with a new program and the variants exist to provide flexibility in passing arguments. 
```

5. Now write a program that uses `wait()` to wait for the child process to finish in the parent. What does `wait()` return? What happens if you use `wait()` in the child?

```cpp
 <img width="1255" height="569" alt="Screenshot 2025-09-24 223846" src="https://github.com/user-attachments/assets/490a5219-d805-4fce-b760-a5919b58a562" />
wait() blocks the parent until a child finishes and returns the child's PID. If a child calls it, then it fails because it has no children. 
```

6. Write a slight modification of the previous program, this time using `waitpid()` instead of `wait()`. When would `waitpid()` be useful?

```cpp
 <img width="1374" height="576" alt="Screenshot 2025-09-24 224142" src="https://github.com/user-attachments/assets/9fe5f766-9fa7-4ed9-8f46-2350800f018f" />
<img width="1397" height="566" alt="Screenshot 2025-09-24 224155" src="https://github.com/user-attachments/assets/57900f24-6139-4f9b-903d-fecbe74a47b1" />
waitpid() lets the parent wait for a specific child which is useful when multiple children are running. 
```

7. Write a program that creates a child process, and then in the child closes standard output (`STDOUT FILENO`). What happens if the child calls `printf()` to print some output after closing the descriptor?

```cpp
<img width="1407" height="577" alt="Screenshot 2025-09-24 224218" src="https://github.com/user-attachments/assets/929f377f-cfa6-40d0-b208-d56fe4a8cc56" />
Closing STDOUT in the child prevents it from printing anything but the parent's output is unaffected. 
```

