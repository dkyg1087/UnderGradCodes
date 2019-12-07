library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity detect_111_00 is
 port(clk,reset,x:in std_logic;
      F:out std_logic);
end detect_111_00;
architecture detect_111_00 of detect_111_00 is
 signal shift_reg:std_logic_vector(2 downto 0);
begin
 process(clk,reset)
 begin
  if reset='0' then
   shift_reg<="000";
  elsif clk'event and clk='1'then
   shift_reg<=x & shift_reg(2 downto 1);
  end if;
 end process;
 F<='1' when shift_reg="111" else
    '1' when shift_reg="001" else
  '1' when shift_reg="000" else
  '0';
end detect_111_00;