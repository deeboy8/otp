# lesson summaries

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

## 10/20

- feeling better about job vs. career
- discussed LinkedIn (LI) style (too informal?) and migrating your resume’s *About Me* section to an *Objectives* section
- decided to stick with – and I won’t tempt you with other projects 😎 – `OTP` as it’s already a known quantity, and is written to be net-centric (client/server – C/S)  
  - as an aside, future projects – like `Huffman` – can be architected to be C/S as well
- did a deep-ish dive into :
  - [getopt(3): Parse options - Linux man page](https://linux.die.net/man/3/getopt)

### next

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
