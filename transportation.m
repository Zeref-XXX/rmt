format short
clear all
clc
%% input data,A= SUPPLY,B=DEMAND
cost=[14 56 48 27;
      82 35 21 81; 
      99 31 71 63];
A=[13 19 16];
B=[7 14 21 6];
%% check balanced or unbalanced 
if sum(A)==sum(B)
    fprintf('balanced \n');
else 
    fprintf('unbalanced \n');
    if sum(A)< sum(B)
       cost (end+1,:)=zeros(1,size (A,2));
       A(end+1)=sum (B)-sum (A);
    elseif sum(B)< sum(A)
    cost (:,end+1)=zeros(1,size (A,2));
       B(end+1)=sum (A)-sum (B);
    end
end
%% NWCR METHOD
x=zeros(size (cost));
[m,n]=size(cost);
BFS = m+n-1;
for i=1:m
    for j=1:n
