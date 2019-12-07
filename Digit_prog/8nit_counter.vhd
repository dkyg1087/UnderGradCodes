library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity HW_counter_8bit is
	port(clk,reset,cmd,Cin:in std_logic;
		  Cout:out std_logic;
		  S:out std_logic_vector(7 downto 0));
end HW_counter_8bit;

architecture HW_counter_8bit of HW_counter_8bit is

	component HW_counter_4bit is
	port(clk,reset,cmd,Cin:in std_logic;
		  Cout:out std_logic;
		  S:out std_logic_vector(3 downto 0));
	end component;

	signal sig:std_logic;
begin
Lo:HW_counter_4bit port map(
	clk=>clk,
	reset=>reset,
	cmd=>cmd,
	Cin=>Cin,
	Cout=>sig,
	S=>S(3 downto 0)
);
Hi:HW_counter_4bit port map(
	clk=>clk,
	reset=>reset,
	cmd=>cmd,
	Cin=>sig,
	Cout=>Cout,
	S=>S(7 downto 4)
);
end HW_counter_8bit;