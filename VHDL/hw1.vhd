library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity hw1 is

	port (A:in std_logic_vector(2 downto 0);
			B:in std_logic_vector(2 downto 0);
			mode:in std_logic;
			S:out std_logic_vector(2 downto 0);
			Co:out std_logic);
end hw1;

architecture hw1 of hw1 is

signal p,q:std_logic;

begin
		S(0) <= A(0) xor (B(0) xor mode) xor mode;
		p <= (A(0) and (B(0) xor mode)) or (A(0) and mode) or ((B(0) xor mode) and mode);
		
		S(1) <= A(1) xor (B(1) xor mode) xor p;
		q <= (A(1) and (B(1) xor mode)) or (A(1) and p) or ((B(1) xor mode) and p);
		
		S(2) <= A(2) xor (B(2) xor mode) xor q;
		Co <= (A(2) and (B(2) xor mode)) or (A(2) and q) or ((B(2) xor mode) and q);
end hw1;
