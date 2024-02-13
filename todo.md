# lesson summaries

## 2/9

- discussed priorities/progress and being in the right _mood_ for differrent _types_ of work and taking advantage of _time-shifting_
- reviewed how we partitioned `otp` into two parts:
  - **UI**: command line args
    - testing via invocations w/combinations of CLAs, driven from a script (black-box)
  - **algorithm**: key generation, encoding and decoding related `f()`-s
    - testing via μunit tests (white-box)
- wrote a simple UT - `encode_one_char()`  - using the _AAA_ pattern

### next - 2/9

- using μunit's `setup()` and `teardown()` (if needed) to setup known (_expected_) `key`, `plain text` and `cipher text` values for use in UTs
- write both _positive_ (**S**ubject **U**nder **T**est - in this case the `f()` under test - passes) and _negative_ (SUT fails...but UT still passes as failure is the _expected_ value) UTs

## 12/31

- discussed holiday celebrations
- had a lengthy discussion on how you appreciated the delination (client/server, UI/functionality...) and how the principal of _separation of concerns_ (SoC) is a good thing - based on _input UI_ (in `otp` - the command line), _transformation_ (computation) and *output UI*
- added _help_ CLA but introduced a bug along the way

### next - 12/31

>> same

---

## 12/24

- discussed `FILE*` vs. file descriptors (`int`) - see [stdio](https://www.man7.org/linux/man-pages/man3/stdio.3.html) versus [fcntl](https://www.man7.org/linux/man-pages/man2/fcntl.2.html)
  - [fileno](https://www.man7.org/linux/man-pages/man3/fileno.3.html) extracts the`fd` from a given `FILE*`
- had a discussion on the approach you were taking - implementing functionality - and the approach I wanted you to take, which is to get the UI (CLAs) working first, using more of a _top-down_ approach and _stubs_, and then use TDD to implement the actual functionality (vs. the initial _stubs_)

>>> - I think we're on the same page now - **yes?**

- talked through the _pure_ and _adulterated_ approaches to TDD
  - essentially when the `.h` file is created for the _SUT_ (subject under test), _e.g._, `encode()`, `decode()`, _etc._ - due to modern-day tooling

### next - 12/24

- [ ] complete the UI
  - [ ] implementation
  - [ ] testing (script of different valid/invalid invocations)

---

## 12/16

- couldn't find a definition for _decoupling_, but I think _parameterization_ is a better term:
  - adds flexibility - including testability
  - makes for more concise code
  - make code easier to maintain
- a summary of [Linux Signals](<misc/Linux Signals.md>)
- a summary of `C` [compiler phases](https://en.cppreference.com/w/c/language/translation_phases)
  > - let's look at the `-E` option again
- patched read loop, to make forward progress, but introduced a constraint WRT `\n`:
  - need to do some research on how different _read_ functions handle `\n` and/or when `stdin` is the keyboard

## next 12/16

- [ ] keep making forward progress on completing the UI
  > you can always go back and fix issues in a second pass
- [ ] create a UI test script w/different invocations
  - [ ] consider creating _golden_ test files and automate further by comparing ([diff(1): compare files line by line](https://linux.die.net/man/1/diff)) **actual** to **expected** (golden)

---

## 12/12

- bug fixing...**AKA** how to pass command line argument(s) (CLAs) to `otp` when using the debugger
- started to evolve _stubs_ (signatures, mock return values) to their final version
  - pair-programmed (PP) `keygen()` *stub*
  - discussed _p-code_ for `encode()`/`decode()`

### next - 12/12

- [ ] see: **next - 12/10** 😎
- [ ] more specifically;  `encode()`/`decode()` to level of `key_gen` (_stub_) so UI can be completed - implementation, test and structure/documentation

### references - 12/12

## 12/10

- _stubs_ - in this/our context - are merely function definitions (_i.e_., implementations) that allow you to make progress, _e.g._,
  > **reminder** - if there's a reference to a (function) - a _declaration_ enables compilation, a _defintion_ enables linking

  ```C
  return_type encode(...params...) {
    fprintf(stderr, "encode: ...\n", params);
    return success;
  }
  ```

- enabling compilation (declarations) and linking (definitions) are steps in the **TDD** process
- **that's all folks**...Lesson displaceed by tickets to:
- ![Go Hawks](https://th.bing.com/th?id=OIF.ypvcLGQKBXGC%2f2ca%2bYR5qg&rs=1&pid=ImgDetMain)
  - **may the best team win**..._kidding_...**Go Hawks**❗❗❗

### next - 12/10

- see: **next - 12/06**

## 12/06

- discussed different ways of looking at life and how we feel both/either at different points in time😎
![Pushing Boulder Uphill](https://miro.medium.com/max/880/1*dKf6Q2WJ1RGZlPjvUbPNFw.gif "Pushing Boulder Uphill")

![Biorhythms](https://www.intmath.com/trigonometric-graphs/img/biorhythms.gif "Biorhythms")

> not that I _believe_ in biorhythms; but their _wave chart_ works well for illustrative purposes😎

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
  - **backburnered** _projects:_  
    ~~1. **job/career**~~  
      ~~- LinkedIn~~  
        ~~- [ ] review other’s LI style to determine what’s next~~  
      ~~- resume~~  
        ~~- [ ] resume _v.Next_~~  
    ~~2. **LI projects**~~  
      ~~- [ ] review, build, _etc._~~  
  - **focussed** _projects:_  
    - **otp**
        1. [ ] user interface:  
          - design and implement (`getopt()` loop) command line args, input/output files (named and standard), _etc._  
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
      - [ ] command line args, std files and named files – convention for _standard_ handles is `-`
      - [ ] spec out/implement CLA/getopt(0 loop for otp…

---

## 10/28

- let's organize around three _projects_:
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
- discussed LinkedIn (LI) style (too informal?) and migrating your resume’s _About Me_ section to an _Objectives_ section
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
