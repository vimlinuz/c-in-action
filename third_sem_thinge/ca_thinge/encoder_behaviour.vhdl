library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity encoder is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : out  STD_LOGIC_VECTOR (1 downto 0));
end encoder;

architecture Behavioral of encoder is
begin
    process(A)
    begin
        case A is
            when "0001" => B <= "00"; 
            when "0010" => B <= "01"; 
            when "0100" => B <= "10"; 
            when "1000" => B <= "11"; 
            when others => B <= (others => 'Z');
        end case;
    end process;
end Behavioral;
