library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity HW2 is
    port(
        A:in std_logic_vector(7 downto 0);
        B:in std_logic_vector(7 downto 0);
        C:in std_logic;
        func:in std_logic_vector(2 downto 0);
        F:out std_logic_vector(7 downto 0);
        Co:out std_logic
    );
end HW2;
architecture HW2 of HW2 is
    signal t1:std_logic_vector(4 downto 0);
	signal t2:std_logic_vector(4 downto 0);
	signal f1:std_logic_vector(3 downto 0);
	signal f2:std_logic_vector(3 downto 0);
    signal ca:std_logic;
    begin
        t1<=('0'&A(3 downto 0))+('0'&B(3 downto 0))+C when func="000" else
            ('0'&A(3 downto 0))-('0'&B(3 downto 0)) when func="001" else
            ('0'&A(3 downto 0))and('0'&B(3 downto 0)) when func="010" else
            ('0'&A(3 downto 0))or('0'&B(3 downto 0)) when func="011" else
            not ('0'&A(3 downto 0)) when func="100" else
            ('0'&A(3 downto 0))+1 when func="101" else
            ('0'&A(3 downto 0))-1 when func="110" else
            (A(3 downto 0)&'0');
        f1<=t1(3 downto 0);
        ca<=t1(4);
        t2<=('0'&A(7 downto 4))+('0'&B(7 downto 4))+ca when func="000" else
			('0'&A(7 downto 4))-('0'&B(7 downto 4))-ca when func="001" else
			('0'&A(7 downto 4))and('0'&B(7 downto 4)) when func="010" else
			('0'&A(7 downto 4))or('0'&B(7 downto 4)) when func="011" else
			not ('0'&A(7 downto 4)) when func="100" else
			('0'&A(7 downto 4))+ca when func="101" else
			('0'&A(7 downto 4))-ca when func="110" else
			(A(7 downto 4)&ca);
	    f2<=t2(3 downto 0);
	    Co<=t2(4);
	    F<=f2&f1;
	end HW2;
	