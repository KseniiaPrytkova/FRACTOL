# FRACTOL
This project is meant to create graphically beautiful fractals.

### Burning Ship fractal:
![alternativetext](screenshots/burning_ship_1.png)
### Burning Ship fractal #2:
![alternativetext](screenshots/burning_ship_3.png)
### Mandelbrot set:
![alternativetext](screenshots/mandelbrot_1.png)
### Mandelbrot set #2:
![alternativetext](screenshots/mandelbrot_2.png)
### Julia set:
![alternativetext](screenshots/julia_1.png)
### Julia set #2:
![alternativetext](screenshots/julia_3.png)

### Run on your local machine:
1. download `go_FRACTOL` folder;
2. run `./fractol ` and you will see the list of available fractals;
3. run `./fractol fractal_name` (ex: `./fractol mandelbrot_set`);
4. follow the legend that you will see in your terminal window.

In this project i use an image approach for drawing, but multithreading is not implemented, therefore at large values ​​of height and width of the screen the program will work slowly.

### What i did implement:
- [x] It is possible to move the fractal (left, right, up, down);
- [x] Zoom (mouse wheel or mouse buttons);
- [x] Changing the depth (so u can see additional color spectrum at each particular section of the fractal);
- [x] Reset when researching of fractal went too far;
- [x] Several variants of color representation are chosen;
- [x] You can change the Julia's coefficients with your mouse, and plunge into the interactive psychedelic of this fractal for a long time;
- [ ] Multithreading;
- [ ] 3D representation;

#### Links
* [List of fractals by Hausdorff dimension](https://en.wikipedia.org/wiki/List_of_fractals_by_Hausdorff_dimension)
* [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)
* [Burning Ship fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
* [Coding Challenge #21: Mandelbrot Set with p5.js](https://youtu.be/6z7GQewK-Ks) - The Coding Train, YouTube
* [Coding Challenge #22: Julia Set in Processing](https://youtu.be/fAsaSkmbF5s) - The Coding Train, YouTube

