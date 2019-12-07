library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity HW_counter_4bit is
	port(clk,reset,cmd,Cin:in std_logic;
		  Cout:out std_logic;
		  S:out std_logic_vector(3 downto 0));
end HW_counter_4bit;

architecture HW_counter_4bit of HW_counter_4bit is
	signal Counter:std_logic_vector(3 downto 0);
begin
	process(clk,reset,Cin)
	begin
		if reset='0' then  /*如果reset是0就洗掉全部變0*/
			Counter<="0000";
		elsif clk'event and clk='1' and Cin='1' then/*正源觸發*/
			if cmd='0' then/*0做上數*/
				if Counter="1111" then
					Counter<="0000";
				else
					Counter<=Counter+"0001";
				end if;
			elsif cmd='1' then/*1做下數*/
				if Counter="0000" then
					Counter<="1111";
				else
					Counter<=Counter-"0001";
				end if;
			end if;
		end if;
	end process;
	S<=Counter;
	Cout<='1' when cmd='0' and Cin='1' and Counter="1111" else
			  '1' when cmd='1' and Cin='1' and Counter="0000" else
			  '0';
end HW_counter_4bit;
