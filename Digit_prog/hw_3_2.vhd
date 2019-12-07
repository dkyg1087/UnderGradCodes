library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_arith.all;
use ieee.std_logic_unsigned.all;
entity HW3_2 is
port(CLK : in std_logic;
A : in std_logic_vector(1 downto 0);
B : out std_logic);
end HW3_2;
architecture HW3_2 of HW3_2 is
signal r3 : std_logic_vector(1 downto 0);
signal r30 : std_logic_vector(4 downto 0);
signal r300 : std_logic_vector(8 downto 0);
begin
    process(CLK,A)
    begin
        if A="00" then 
            if CLK'event and CLK='1' then
                if r3="10" then
                    r3 <= "00";
                else
                    r3 <= r3 + "01";
                end if;
            end if;
            if r3="00" then
                B <= '1';
            elsif r3="01" then
                B <= CLK;
            else
                B <= '0';
            end if;
        elsif A="01" then 
            if CLK'event and CLK='1' then
                if r30="11101" then
                    r30 <= "00000";
                else
                    r30 <= r30 + "00001";
                end if;
            end if;
            if r30 < "01111" then
                B <= '1';
            else
                B <= '0';
            end if;
        elsif A="10" or A="11" then 
            if CLK'event and CLK='1' then
                if r300="100101011" then
                    r300 <= "000000000";
                else
                    r300 <= r300 + "000000001";
                end if;
            end if;
            if r300 < "010010110" then
                B <= '1';
            else
                B <= '0';
            end if;
        end if;
    end process;
end HW3_2;