# pianika-c-SDL2

**Pianika** is a simple application that lets you play virtual piano keys using your keyboard. This application is built using SDL2, SDL_ttf, and SDL_mixer, and supports various instrument sounds that can be played with keyboard keys.
![image](https://e.top4top.io/p_3162jdg750.jpg)

## Features

- **Virtual Piano Keys:** Play piano keys using the keyboard buttons `A`, `S`, `D`, `F`, `G`, `H`, `J`, `K`, `L`, `M`.
- **Visual Feedback:** The piano keys change color when pressed to provide visual feedback.
- **Realistic Sounds:** Each key has a unique sound, simulating a real piano experience.

## Getting Started

To get started with Pianika, follow these steps:

### Prerequisites

- **SDL2**: Make sure you have SDL2 installed on your system.
- **SDL_ttf**: This library is used for rendering text.
- **SDL_mixer**: This library handles audio playback.
- **A C++ Compiler**: Ensure you have a C++ compiler installed (like `g++`).

### Installation

1. **Clone the Repository**

   ```bash
   git clone https://github.com/Zreechxnn/pianika-c-SDL2.git
   cd pianika-c-SDL2
   ```

2. **Install Dependencies**

   On Ubuntu-based systems, you can install the necessary libraries using:

   ```bash
   sudo apt-get install libsdl2-dev libsdl2-mixer-dev libsdl2-ttf-dev
   ```

   On other systems, please refer to the respective package managers or build from source.

3. **Build the Project**

   ```bash
   g++ -o pianika pianika.cpp -lSDL2 -lSDL2_mixer -lSDL2_ttf
   ```

4. **Run the Application**

   ```bash
   ./pianika
   ```

### Usage

- Press the following keys to play different piano notes:
  - `A` - Do
  - `S` - Re
  - `D` - Mi
  - `F` - Fa
  - `G` - Sol
  - `H` - La
  - `J` - Si
  - `K` - Do (Stretched)
  - `L` - Fa (Stretched)
  - `M` - Sol (Stretched)

- The keys will turn red when pressed and revert to black when released.

### Assets

Make sure to place your sound files and font file in the `assets` directory:
- `do.wav`
- `re.wav`
- `mi.wav`
- `fa.wav`
- `sol.wav`
- `la.wav`
- `si.wav`
- `do_stretched.wav`
- `fa_stretched.wav`
- `sol_stretched.wav`
- `arial.ttf`

### Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes. For major changes, please open an issue first to discuss what you would like to change.

### License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

### Contact

For any questions or suggestions, please contact [zreechxnn(mailto:hoshikochan93@gmail.com).

---

Enjoy playing the virtual piano with Pianika!

---

Feel free to customize the sections, such as the repository URL, contact details, or license information, as needed.
