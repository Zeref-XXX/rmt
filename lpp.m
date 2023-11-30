% Define coefficients and constraints
c = [-1; -2];  % Coefficients of the objective function
A = [1 0; 0 3];  % Coefficients of the inequality constraints
b = [4; 6];  % Right-hand side values of the constraints
% Define the feasible region
x1 = linspace(0, 10, 100);  % Define a range of x1 values
x2_1 = (b(1) - A(1,1)*x1) / A(1,2);  % Calculate corresponding x2 values for constraint 1
x2_2 = (b(2) - A(2,1)*x1) / A(2,2);  % Calculate corresponding x2 values for constraint 2
% Plot the feasible region
figure;
plot(x1, x2_1, 'r', 'LineWidth', 2);  % Plot constraint 1
hold on;
plot(x1, x2_2, 'g', 'LineWidth', 2);  % Plot constraint 2
xlabel('x1');
ylabel('x2');
title('Feasible Region');
legend('a11x1 + a12x2 <= b1', 'a21x1 + a22x2 <= b2');
% Find corner points
corners_x1 = [0, 0, 3];
corners_x2 = [2, 4, 1];
plot(corners_x1, corners_x2, 'bo', 'MarkerSize', 10, 'MarkerFaceColor', 'b');
% Calculate objective function value at corner points
z = c(1)*corners_x1 + c(2)*corners_x2;
% Find the optimal solution
[Z_optimal, idx] = max(z);
x1_optimal = corners_x1(idx);
x2_optimal = corners_x2(idx);
% Plot the optimal point
plot(x1_optimal, x2_optimal, 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'r');
text(x1_optimal + 0.5, x2_optimal, ['Optimal (' num2str(x1_optimal) ', ' num2str(x2_optimal) ')'], 'Color', 'r');
% Print the optimal solution and value of the objective function
disp(['Optimal Solution: x1 = ' num2str(x1_optimal) ', x2 = ' num2str(x2_optimal)]);
disp(['Optimal Value of Objective Function (Z): ' num2str(Z_optimal)]);
