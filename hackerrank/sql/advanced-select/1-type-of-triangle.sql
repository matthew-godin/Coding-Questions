select
case
    when A = B then
        case
            when A = C then 'Equilateral'
            else
                case
                    when A + B <= C or A + C <= B or B + C <= A then 'Not A Triangle'
                    else 'Isosceles'
                end
        end 
    else
        case
            when B = C then
                case
                    when A + B <= C or A + C <= B or B + C <= A then 'Not A Triangle'
                    else 'Isosceles'
                end
            else
                case
                    when A = C then
                        case
                            when A + B <= C or A + C <= B or B + C <= A then 'Not A Triangle'
                            else 'Isosceles'
                        end
                    else
                        case
                            when A + B <= C or A + C <= B or B + C <= A then 'Not A Triangle'
                            else 'Scalene'
                        end
                end
        end
end
from TRIANGLES