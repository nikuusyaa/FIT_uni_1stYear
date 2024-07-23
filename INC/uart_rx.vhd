-- uart_rx.vhd: UART controller - receiving (RX) side
-- Author(s): Veronika Borozenets (xborozv00)

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;



-- Entity declaration (DO NOT ALTER THIS PART!)cd 
entity UART_RX is
    port(
        CLK      : in std_logic;
        RST      : in std_logic;
        DIN      : in std_logic;
        DOUT     : out std_logic_vector(7 downto 0);
        DOUT_VLD : out std_logic
    );
end entity;



-- Architecture implementation (INSERT YOUR IMPLEMENTATION HERE)
architecture behavioral of UART_RX is
    signal CNT_C   : std_logic_vector(4 downto 0);  -- clock counter
    signal CNT_D   : std_logic_vector(3 downto 0);  -- data counter
    signal VLD     : std_logic;                     -- validation signal
    signal DCNT_EN : std_logic;        
    signal RDY     : std_logic;   
    
begin

    -- Instance of RX FSM
    fsm: entity work.UART_RX_FSM
    port map (
        CLK => CLK,
        RST => RST,
        DIN=> DIN,
        CNT_C=>CNT_C,
        CNT_D=> CNT_D,
        DOUT_VLD=> VLD,
        DCNT_EN=> DCNT_EN,
        RDY=>RDY
    );

    --DOUT <= (others => '0');
    --DOUT_VLD <= '0';

    process (CLK) begin
               DOUT_VLD <= VLD;
			    if rising_edge(CLK) then

				if DCNT_EN = '1' then 
					CNT_C <= CNT_C + 1;
				else 
					CNT_C <= "00000";
				end if;
                -- reset data counter and clk counter if data counter reaches its maximum value
				if CNT_D = "1000" then
					CNT_C <= "00000";
					CNT_D <= "0000";
				end if;

				if RDY = '1' then
					if CNT_C = "10111" then
                              CNT_D <= CNT_D + 1;
                              CNT_C <= "01000";
                    -- copy input data to the output bit
					case CNT_D is
						when "0000" => DOUT(0) <= DIN;
						when "0001" => DOUT(1) <= DIN;
						when "0010" => DOUT(2) <= DIN;
						when "0011" => DOUT(3) <= DIN;
						when "0100" => DOUT(4) <= DIN;
						when "0101" => DOUT(5) <= DIN;
						when "0110" => DOUT(6) <= DIN;
						when "0111" => DOUT(7) <= DIN;
						when others => null;
					end case;
					end if;
				else
					CNT_D <= "0000";
				end if;
			end if;
		end process;
end architecture;
