# lesson summaries

## 12/16

- couldn't find a definition for *decoupling*, but I think *parameterization* is a better term:
  - adds flexibility - including testability
  - makes for more concise code
  - make code easier to maintain
- a summary of [Linux Signals](<misc/Linux Signals.md>)
- a summary of `C` [compiler phases](https://en.cppreference.com/w/c/language/translation_phases)
  > - let's look at the `-E` option again
- patched read loop, to make forward progress, but introduced a constraint WRT `\n`:
  - need to do some research on how different *read* functions handle `\n` and/or when `stdin` is the keyboard

## next 12/16

- [ ] keep making forward progress on completing the UI
  > you can always go back and fix issues in a second pass
- [ ] create a UI test script w/different invocations
  - [ ] consider creating *golden* test files and automate further by comparing ([diff(1): compare files line by line](https://linux.die.net/man/1/diff)) **actual** to **expected** (golden)

---

## 12/12

- bug fixing...**AKA** how to pass command line argument(s) (CLAs) to `otp` when using the debugger
- started to evolve *stubs* (signatures, mock return values) to their final version
  - pair-programmed (PP) `keygen()` *stub*
  - discussed *p-code* for `encode()`/`decode()`

### next - 12/12

- [ ] see: **next - 12/10** 😎
- [ ] more specifically;  `encode()`/`decode()` to level of `key_gen` (*stub*) so UI can be completed - implementation, test and structure/documentation

### references - 12/12

## 12/10

- *stubs* - in this/our context - are merely function definitions (*i.e*., implementations) that allow you to make progress, *e.g.*,
  > **reminder** - if there's a reference to a (function) - a *declaration* enables compilation, a *defintion* enables linking

  ```C
  return_type encode(...params...) {
    fprintf(stderr, "encode: ...\n", params);
    return success;
  }
  ```

- enabling compilation (declarations) and linking (definitions) are steps in the **TDD** process
- **that's all folks**...Lesson displaceed by tickets to:
- ![Go Hawks](https://th.bing.com/th?id=OIF.ypvcLGQKBXGC%2f2ca%2bYR5qg&rs=1&pid=ImgDetMain)
  - **may the best team win**...*kidding*...**Go Hawks**❗❗❗

### next - 12/10

- see: **next - 12/06**

## 12/06

- discussed different ways of looking at life and how we feel both/either at different points in time😎
![Pushing Boulder Uphill](https://miro.medium.com/max/880/1*dKf6Q2WJ1RGZlPjvUbPNFw.gif "Pushing Boulder Uphill")

![Biorhythms](https://www.intmath.com/trigonometric-graphs/img/biorhythms.gif "Biorhythms")

> not that I *believe* in biorhythms; but their *wave chart* works well for illustrative purposes😎

- fixed string comparison w/macro
- structured `main()` to execute each command
  - refactored for common file I/O in `encode()` and `decode()`
- tweaked makefile, fixed syntax errors...**builds successfully**❗

### next - 12/06

- [ ] create list of UTs for testing the UI (command line)
  - [ ] pass all of these (manual) UTs
- [ ] stubs for `key()`/`encode()`/`decode()`
- [ ] we need to review tdd/aaa & µnit

---

## 11/25

- caught-up on life, and realized that we both have a lot to be thankful for...
- complimentary discussions on:
  - new, exciting work opportunities
  - objectives (personal/pofessional) and *projects*
- yielded:
  - **backburnered** *projects:*  
    ~~1. **job/career**~~  
      ~~- LinkedIn~~  
        ~~- [ ] review other’s LI style to determine what’s next~~  
      ~~- resume~~  
        ~~- [ ] resume *v.Next*~~  
    ~~2. **LI projects**~~  
      ~~- [ ] review, build, *etc.*~~  
  - **focussed** *projects:*  
    - **otp**
        1. [ ] user interface:  
          - design and implement (`getopt()` loop) command line args, input/output files (named and standard), *etc.*  
        2. [ ] review (preferably in debugger) µnit's `example.c`

---

## 11/04

- discussion on the state of the world... 🎼... Be happy❗😎
- *projects:*
  1. **job/career**
     - LinkedIn
       - [ ] review other’s LI style to determine what’s next
     - resume
       - [ ] resume *v.Next*
  2. **LI projects**
     - [ ] review, build, *etc.*
  3. **otp**
      - [ ] command line args, std files and named files – convention for *standard* handles is `-`
      - [ ] spec out/implement CLA/getopt(0 loop for otp…

---

## 10/28

- let's organize around three *projects*:
  1. **job/career**
     - LinkedIn
       - [ ] review other’s LI style to determine what’s next
     - resume
       - [ ] resume *v.Next*
  2. **LI projects**
     - [ ] review, build, *etc.*
  3. **`otp`**:
     - Still organizing – **gitpod**, **kanbn**, **todo tree**, **live share**…
       - [ ] take a look at Kanbn and to do tree
         - [ ] [Kanbn Extension for Visual Studio Code - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=gordonlarrigan.vscode-kanbn)
         - [ ] [Todo Tree - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=Gruntfuggly.todo-tree)
     - [ ] make a makefile
       - create your own as the `replit.com` version won't work w/multiple `main()`-s - `otp` and `munit`
       - ~~potentially use repl's makefile~~
         - ~~tell it to show hidden file (hides makefile)~~
     - [ ] review [µnit](https://nemequ.github.io/munit/) docs
       - [ ] download `.c` and `.h` file and upload to `otp` repo
       - [ ] step through `munit` example code to refresh memory
     - [ ] design all three commands for commandline
       - refer back to notes from Wyzant notes (add to repo)

---

## 10/20

- feeling better about job vs. career
- discussed LinkedIn (LI) style (too informal?) and migrating your resume’s *About Me* section to an *Objectives* section
- decided to stick with – and I won’t tempt you with other projects 😎 – `OTP` as it’s already a known quantity, and is written to be net-centric (client/server – C/S)  
  - as an aside, future projects – like `Huffman` – can be architected to be C/S as well
- did a deep-ish dive into :
  - [getopt(3): Parse options - Linux man page](https://linux.die.net/man/3/getopt)

### next - 10/20

- [ ] complete dev. env. setup
  - github/replit/gitpod
- VS Code, consider these extensions (they don't work in any of the browser envs.):
  - [Kanbn Extension for Visual Studio Code - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=gordonlarrigan.vscode-kanbn)
- [ ] review other’s LI style to determine what’s next
- [ ] resume *v.Next*
- [ ] recreate `OTP` repl (missing `makefile`) as it’s early and there’s very little to migrate
  - When complete, push all updates to repo
- [ ] design all three command lines
- [ ] implement `keygen`

---

## 10/13

- complete dev. env. setup
  - github/replit/gitpod
  - VS Code, consider these extensions (they don't work in any of the browser envs.)
    - [Live Share - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=MS-vsliveshare.vsliveshare)
      - [Use Microsoft Live Share to collaborate with Visual Studio Code](https://code.visualstudio.com/learn/collaboration/live-share)
      - [Install and sign in to Live Share in Visual Studio Code - Live Share | Microsoft Learn](https://learn.microsoft.com/en-us/visualstudio/liveshare/use/install-live-share-visual-studio-code)
    - [Kanbn Extension for Visual Studio Code - Visual Studio Marketplace](https://marketplace.visualstudio.com/items?itemName=gordonlarrigan.vscode-kanbn)
- create a skeleton `main()` that can choose to then run - `keygen`, `encrypt`, `decrypt` - based on a command line option
  - consider: [getopt(3) - Linux manual page](https://www.man7.org/linux/man-pages/man3/getopt.3.html)
