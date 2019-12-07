library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity multiply_4bit is
port(	Cin1: in std_logic_vector(3 downto 0);
		Cin2:	in std_logic_vector(3 downto 0);
		Cout: out std_logic_vector(7 downto 0));
end multiply_4bit;
architecture multiply_4bit of multiply_4bit is
	signal x: std_logic_vector(7 downto 0);
	begin
	x<=Cin1*Cin2;
	Cout<=x;
end multiply_4bit;
