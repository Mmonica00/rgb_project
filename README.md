# 💡 RGB LED Project (Raspberry Pi Pico)

This project controls an RGB LED using the **Raspberry Pi Pico** or **Arduino Nano RP2040** microcontroller.  
It’s written in **C**, built with **CMake** + **Ninja**, and uses the **Raspberry Pi Pico SDK**.

---

## 🧰 Project Structure

```
rgb_project/
├── CMakeLists.txt          # CMake configuration
├── main.c                  # Your main application source code
├── pico_sdk_import.cmake   # Imports the Pico SDK
└── build/                  # Auto-generated build directory
    ├── compile_commands.json
    ├── main.uf2
    └── ...
```

---

## ⚙️ Requirements

Before starting, make sure you have both the **Pico SDK** and this **project repository** cloned locally.

### 🧩 Clone the Project and SDK

```bash
# Create a workspace folder
mkdir -p ~/pico
cd ~/pico

# Clone the Raspberry Pi Pico SDK
git clone -b master https://github.com/raspberrypi/pico-sdk.git
cd pico-sdk
git submodule update --init

# Go back and clone this project
cd ..
git clone https://github.com/<your-username>/rgb_project.git
```

This creates the following structure:
```
pico/
├── pico-sdk/
└── rgb_project/
```

---

## 🖥️ On macOS
```bash
brew install cmake ninja arm-none-eabi-gcc
```

---

## 🪟 On Windows (Detailed Setup)

To build and upload your project from Windows, you need a few developer tools. Follow these steps carefully:

### 1. 🧱 Install CMake
- Download the latest version from [CMake.org](https://cmake.org/download/).  
- During installation, **check the box** that says:  
  > “Add CMake to system PATH for all users”  
- Verify it’s installed correctly:
  ```powershell
  cmake --version
  ```

### 2. ⚡ Install Ninja
- Go to [Ninja Releases](https://github.com/ninja-build/ninja/releases).  
- Download `ninja-win.zip`.
- Extract `ninja.exe` to a directory, for example:
  ```
  C:\Tools\ninja
  ```
- Add that directory to your **PATH**:
  - Control Panel → System → Advanced System Settings → Environment Variables  
  - Under “System variables,” edit `Path` → Add `C:\Tools\ninja`
- Test it:
  ```powershell
  ninja --version
  ```

### 3. 🧰 Install ARM GCC Toolchain
- Download the **Arm GNU Toolchain for Windows (arm-none-eabi)** from:  
  👉 [ARM GNU Toolchain Downloads](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- Choose the latest version for Windows (x86_64).
- Install it to:
  ```
  C:\Program Files (x86)\Arm GNU Toolchain\arm-none-eabi\bin
  ```
- Add that `bin` folder to your PATH.  
- Check the installation:
  ```powershell
  arm-none-eabi-gcc --version
  ```

### 4. 💻 Install VS Code
- Download and install [Visual Studio Code](https://code.visualstudio.com/).
- From the Extensions tab, install:
  - **C/C++** (by Microsoft)
  - **CMake Tools**
  - (Optional) **CMake** syntax highlighter
- These provide IntelliSense, build tools, and debugging support.

### 5. 🔧 Verify Everything
Open **PowerShell** or **Command Prompt**, and run:
```powershell
cmake --version
ninja --version
arm-none-eabi-gcc --version
```
If all three commands return a version number — your environment is ready!

---

## 🚀 Building the Project

### macOS / Linux
```bash
cd ~/pico/rgb_project
mkdir -p build
cd build
cmake -G "Ninja" -DPICO_SDK_PATH=~/pico/pico-sdk ..
ninja
```

### Windows (PowerShell)
```powershell
cd C:\pico\rgb_project
mkdir build
cd build
cmake -G "Ninja" -DPICO_SDK_PATH=C:\pico\pico-sdk ..
ninja
```

If successful, you’ll see:
```
[100%] Built target main
```

Your compiled UF2 file will appear at:
```
rgb_project/build/main.uf2
```

---

## 🔌 Flashing to the Pico

1. Hold down the **BOOTSEL** button on your Raspberry Pi Pico.  
2. Plug it into your computer’s USB port.  
3. It will appear as a drive named `RPI-RP2`.  
4. Drag and drop `main.uf2` into that drive.  
5. The Pico will reboot automatically and start running your program.

---

## 💡 LED Circuit Wiring

| LED Pin        | Connect To                       | Notes                         |
|----------------|----------------------------------|--------------------------------|
| **Common Cathode** | **GND**                          | Longest leg                    |
| **R**          | GPIO 11 (through 220 Ω resistor) | Red LED pin                    |
| **G**          | GPIO 12 (through 220 Ω resistor) | Green LED pin                  |
| **B**          | GPIO 13 (through 220 Ω resistor) | Blue LED pin                   |

💡 Use 220–330 Ω resistors to protect your GPIO pins.

---

## 🧠 Enable IntelliSense in VS Code

To enable code completion and error checking:

1. Open Command Palette → `C/C++: Edit Configurations (UI)`
2. Under **“Compile Commands”**, set this path:
   ```
   <your_project_path>/build/compile_commands.json
   ```
3. Save and reload VS Code.

---

## 🧾 Notes

- `set(CMAKE_EXPORT_COMPILE_COMMANDS ON)` in `CMakeLists.txt` ensures VS Code indexing works.
- If you see `ninja: error: loading 'build.ninja'`, rerun `cmake -G "Ninja" ..`.
- If `arm-none-eabi-gcc` is missing, reinstall via:
  - macOS: `brew install arm-none-eabi-gcc`
  - Windows: Use the [ARM GCC Installer](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads).

---

## 🧠 Credits
- [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)
- [CMake + Ninja Build System](https://ninja-build.org/)

---

**Author:** Monica Samaan  
**Platform:** macOS / Windows  
**Board:** Raspberry Pi Pico / RP2040  
**Language:** C  
**Build System:** CMake + Ninja
