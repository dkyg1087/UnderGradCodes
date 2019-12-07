library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity HW3_1 is
port(CLK,reset,mode : in std_logic;
A : out std_logic_vector(3 downto 0));
end HW3_1;
architecture HW3_1 of HW3_1 is
signal r : std_logic_vector(4 downto 0);
begin
process(CLK,reset)
begin
if reset='0' then
r<="00001";
elsif CLK'event and CLK='1' then
if mode='0' then
case r is
when '0'&"0001" =>r <='0'&"0010";
when '0'&"0010" =>r <='0'&"0100";
when '0'&"0100" =>r <='0'&"1000";
when '0'&"1000" =>r <='1'&"0100";
when '1'&"0100" =>r <='1'&"0010";
when others =>r <='0'&"0001";
end case;
elsif mode='1' then
case r is
when '0'&"0001" =>r <='0'&"0011";
when '0'&"0011" =>r <='0'&"0101";
when '0'&"0101" =>r <='0'&"0111";
when '0'&"0111" =>r <='0'&"1001";
when '0'&"1001" =>r <='1'&"0111";
when '1'&"0111" =>r <='1'&"0101";
when '1'&"0101" =>r <='1'&"0011";
when others =>r <='0'&"0001";
end case;
end if;
end if;
end process;
A<=r(3 downto 0);
end HW3_1;