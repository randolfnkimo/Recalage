# Image Registration Algorithm

## Introduction

This project aims to design an image registration algorithm using object-oriented programming (OOP) principles. Image registration is a crucial process in image processing, enabling the overlay of two images for analysis or comparison. This project was carried out as part of the practical and theoretical coursework in the second year of higher education in computer science.

## Objectives

1. **Registration Algorithm**:
   - Develop an image registration method using a procedural approach followed by an object-oriented approach.
   - Compare the two approaches to identify the advantages of OOP.

2. **Main Classes**:
   - **Image**: Management and manipulation of images.
   - **Point**: Representation and transformation of points in image space.
   - **Transformation**: Application of geometric transformations.
   - **Interpolation**: Interpolation techniques for continuous transformations.
   - **Deformation**: Application of deformations to images using transformations and interpolations.
   - **Similarity**: Evaluation of similarity between registered images.
   - **Evaluation**: Optimization of registration parameters to maximize similarity.

## Project Structure

### Part 1: Procedural Programming

- **Transformation**: Apply basic geometric transformations (rotation, translation) to an image.
- **CostFunction**: Calculate the cost of transformation based on the difference between the transformed image and a reference image.
- **Optimization**: Adjust transformation parameters to minimize the cost.

### Part 2: Object-Oriented Programming

- **Single Responsibility Principle**: Each class has a clear and unique responsibility.
- **Open/Closed Principle**: Classes are open for extension but closed for modification.

#### Classes and Methods

1. **Image Class**:
   - `imread`: Load an image from a file.
   - `imwrite`: Save an image to a file.

2. **Point Class**:
   - `translate`: Apply a translation to a point.
   - `rotate`: Apply a rotation to a point.
   - `distance`: Calculate the distance between two points.

3. **Transformation Class**:
   - `transform`: Apply a geometric transformation to a point.

4. **Interpolation Class**:
   - `interpolate`: Interpolate pixel values for continuous transformations.

5. **Deformation Class**:
   - `deform`: Apply deformations to an image using transformations and interpolations.

6. **Similarity Class**:
   - `resemblance`: Evaluate the similarity between two registered images.

7. **Evaluation Class**:
   - `operator()`: Optimize registration parameters to maximize similarity.

## Expected Outcomes

- A robust and efficient registration algorithm.
- A clear comparison between procedural and object-oriented approaches.
- A practical application of OOP principles in an image processing project.

## Usage

To run this project, follow the steps below:

**1. Clone the Repository:**
```
git clone https://github.com/your-username/your-repo.git
cd your-repo
```
**2. Compile the Code:**
```sh
cd build
cmake ..
make
```
**3. Run the Program:**
```
./bin/recalage
```
## Contact

For any questions or further information, please contact [randolfnkimo@gmail.com].
