library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity demux_2 is
	port(din,s:in std_logic;
	     F:out std_logic_vector(1 downto 0));
end demux_2;
architecture demux_2 of demux_2 is
begin
	F<=din & '1' when s = '0' else
	   '1' & din;
end demux_2;