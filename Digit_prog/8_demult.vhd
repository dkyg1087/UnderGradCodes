library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity demux_8 is
port(din:in std_logic;
     s:in std_logic_vector(2 downto 0);
	  F:out std_logic_vector(7 downto 0));
end demux_8;
architecture demux_8 of demux_8 is
	component demux_2 is
	port(din,s:in std_logic;
	     F:out std_logic_vector(1 downto 0));
	end component;
	component demux_4 is
	port(din:in std_logic;
     s:in std_logic_vector(1 downto 0);
	  F:out std_logic_vector(3 downto 0));
	end component;
	signal x : std_logic_vector(3 downto 0);
begin
	demul1 : demux_4
		port map(din,s(2 downto 1),x);
	lop : for i in 0 to 3 generate
	      demul2 : demux_2
				port map(x(i),s(0),F(2*i+1 downto 2*i));
	end generate lop;
end demux_8;