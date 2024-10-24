# Finite Difference Method (FDM)

This project implements the **Finite Difference Method (FDM)** to numerically solve boundary value problems (BVPs) for differential equations. The solution involves constructing a system of equations using finite differences and solving it via matrix inversion.

## Algorithm Overview

The Finite Difference Method approximates derivatives by replacing them with difference quotients. The continuous domain of the problem is discretized into a set of grid points, and the differential equation is transformed into a system of algebraic equations that can be solved using matrix techniques.

### Steps of the Algorithm

1. **Discretization of the Domain**:
    - The domain of the differential equation is divided into discrete points.
    - For example, consider a 1D domain $x \in [a, b]$ with $N$ grid points. The step size $h$ is:<br>
      $$\begin{equation}h = \frac{b - a}{N-1}\end{equation}$$

2. **Finite Difference Approximation**:
    - The derivatives in the differential equation are approximated using finite differences.
    - For example, the second-order derivative $\frac{d^2u}{dx^2}$ at grid point $x_i$ can be approximated as:<br>
      $$\frac{d^2u}{dx^2} \approx \frac{u_{i+1} - 2u_i + u_{i-1}}{h^2}$$

3. **Matrix Representation**:
    - The discretized equation for all grid points results in a system of linear equations.
    - This system can be written in matrix form $A \mathbf{u} = \mathbf{b}$, where:
        - $A$ is the coefficient matrix, constructed from the finite difference coefficients.
        - $\mathbf{u}$ is the vector of unknowns (solution at each grid point).
        - $\mathbf{b}$ is the vector representing the boundary conditions and any source terms.

### Matrix Representation

For a second-order differential equation like equation:<br>
$$\frac{d^2 u}{dx^2} + u^3(x) = f(x), \quad u(a) = u_a, \quad u(b) = u_b$$
the finite difference method leads to the following system of equations:

$$A \mathbf{u} = \mathbf{b}$$

Where $A$ is a tridiagonal matrix, representing the discretized second derivative:

$$
A =
\begin{pmatrix}
1 & 0 & 0 & 0 & \cdots & 0 \\
-1 & 2 & -1 & 0 & \cdots & 0 \\
0 & -1 & 2 & 1 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \ddots \\
0 & 0 & 0 & -1 & 2 & 1 \\
0 & 0 & 0 & 0 & \cdots & 1
\end{pmatrix}
$$

The vector $\mathbf{u}$ represents the unknown values $u_0, u_1, u_2, \dots, u_{N-1}$ at the internal grid points $x_0, x_1, x_2, \dots, x_{N-1}$. The right-hand side vector $\mathbf{b}$ incorporates boundary conditions and any source terms from the original differential equation.

$$
\mathbf{b} =
\begin{pmatrix}
f(x_0) - u_0^3\\
f(x_1) - u_1^3 \\
f(x_2) - u_2^3 \\
\vdots \\
f(x_{N - 1}) - u_{N - 1}^3
\end{pmatrix}
$$

### Iterative Solution Process

The Finite Difference Method typically involves an iterative approach to solve the system of equations for increasing accuracy. Here’s how the process works:

1. **Initial Guess**:
   Start with an initial guess for the solution vector $\mathbf{u}^{(0)}$. This can be a zero vector or any reasonable approximation for the problem at hand.

2. **Calculate $\mathbf{b}^{(0)}$**:
   Using the initial guess $\mathbf{u}^{(0)}$, calculate the corresponding right-hand side vector $\mathbf{b}^{(0)}$.

3. **Solve for the Next Approximation**:
   Using matrix inversion, solve for the next approximation $\mathbf{u}^{(1)}$ by:
   $$\mathbf{u}^{(1)} = A^{-1} \mathbf{b}^{(0)}$$

4. **Recalculate $\mathbf{b}^{(1)}$**:
   With the updated approximation $\mathbf{u}^{(1)}$, recalculate the right-hand side vector $\mathbf{b}^{(1)}$.

5. **Iterate**:
   Repeat the process, updating $\mathbf{u}^{(n+1)}$ and recalculating $\mathbf{b}^{(n+1)}$ at each step. The solution improves with each iteration.

6. **Convergence Check**:
   Continue iterating until the change in the solution between two successive iterations, $||\mathbf{u}^{(n+1)} - \mathbf{u}^{(n)}||$, is smaller than a predefined tolerance, indicating that the solution has converged.

7. **Stopping Criterion**:
   Once the change in the solution is negligible ( by absolute or relative value) or number of iterations has exceeded predefined limit, stop the iterations. The final $\mathbf{u}^{(n+1)}$ is the approximate solution to the original boundary value problem.

This iterative process refines the approximation with each step, improving the accuracy of the solution until the desired precision is achieved.



$$\mathbf{u} = A^{-1} \mathbf{b}$$

### Example: 

For the 1D equation:<br>
$$\frac{d^2 u}{dx^2} = \sin(x) - u^3(x), \quad u(0) = 0, \quad u(1) = 1$$

The discretized form at interior points $x_0, x_1, x_2, \dots, x_{N-1}$ leads to the matrix equation:<br>
$$A \mathbf{u} = \mathbf{b}$$
where:
$$
A =
\begin{pmatrix}
1 & 0 & 0 & 0 & \cdots & 0 \\
-1 & 2 & -1 & 0 & \cdots & 0 \\
0 & -1 & 2 & 1 & \cdots & 0 \\
\vdots & \vdots & \vdots & \ddots & \ddots \\
0 & 0 & 0 & -1 & 2 & 1 \\
0 & 0 & 0 & 0 & \cdots & 1
\end{pmatrix},
\quad
\mathbf{b} =
\begin{pmatrix}
0 \\
\vdots \\
\sin(x_i) - x_i^3 \\
\vdots \\
1
\end{pmatrix}
$$
As an initial approximation $\mathbf{u}^{(0)}$ we take values of function $x$.
