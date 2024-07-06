CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    (select (select max(salary) from Employee e where (select count(distinct salary) from Employee p where e.salary <= p.salary) = N) as nthHighestSalary)
  );
END