% Objective function coefficients
c = [-3; -5];
% Inequality constraints (Ax <= b)
A = [2 1; 1 2];
b = [8; 6];
% Variable bounds (x >= 0, y >= 0)
lb = [0; 0];
% Solve the linear programming problem
[x, Z] = linprog(c, A, b, [], [], lb);
% Display results
fprintf('Optimal solution:\n');
fprintf('x = %f\n', x(1));
fprintf('y = %f\n', x(2));
fprintf('Optimal value of Z = %f\n', -Z);
