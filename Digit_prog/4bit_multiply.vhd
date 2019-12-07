library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity mult_4bit is
	port(A,B:in std_logic_vector(3 downto 0);
        Ci:in std_logic;
	     S:out std_logic_vector(7 downto 0);
		  Co:out std_logic);
end mult_4bit;
architecture mult_4bit of mult_4bit is
	component FA_8bit is
	port(X,Y:in std_logic_vector(7 downto 0);
		  Ci:in std_logic;
		  S:out std_logic_vector(7 downto 0);
		  Co:out std_logic);
	end component;
	signal p,q:std_logic_vector(7 downto 0);
	signal r1,r2:std_logic;
begin
		Lo:FA_8bit port map(
			X=>"0000"&(A(3) and B(0))&(A(2) and B(0))&(A(1) and B(0))&(A(0) and B(0)),
			Y=>"000"&(A(3) and B(1))&(A(2) and B(1))&(A(1) and B(1))&(A(0) and B(1))&'0',
			Ci=>Ci,
			s=>p,
			Co=>r1
			);
		MD:FA_8bit port map(
			X=>p,
			Y=>"00"&(A(3) and B(2))&(A(2) and B(2))&(A(1) and B(2))&(A(0) and B(2))&"00",
			Ci=>r1,
			s=>q,
			Co=>r2
			);
		Hi:FA_8bit port map(
			X=>q,
			Y=>'0'&(A(3) and B(3))&(A(2) and B(3))&(A(1) and B(3))&(A(0) and B(3))&"000",
			Ci=>r2,
			s=>S,
			Co=>Co
			);
			
end mult_4bit;