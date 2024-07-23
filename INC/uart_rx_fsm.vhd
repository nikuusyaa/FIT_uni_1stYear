-- uart_rx_fsm.vhd: UART controller - finite state machine controlling RX side
-- Author(s): Veronica Borozenets (xborozv00)

library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;



entity UART_RX_FSM is
    port(
    --IN
       CLK   : in std_logic;
       RST   : in std_logic;
       DIN   : in std_logic;
       CNT_C : in std_logic_vector(4 downto 0) ;
       CNT_D : in std_logic_vector(3 downto 0) ;
    --OUT
       RDY      : out std_logic :='0' ;
       DCNT_EN  : out std_logic:= '0';   
       DOUT_VLD : out std_logic := '0'           
    );
end entity;

architecture behavioral of UART_RX_FSM is

    --states of the FSM: IDLE, START, DATA_READ, STOP, VALIDATION
    type state_type is (IDLE, START, DATA_READ, STOP, VALIDATION); 
    --initial state is IDLE
    signal current_state : state_type := IDLE;
    
begin


    
    process(CLK) begin
        if rising_edge(CLK) then
            --if reset then fsm switches to the initial state
            if RST = '1' then
                current_state <= IDLE; 
            else 
                    case current_state is
                    when IDLE=>
                    -- condition from "IDLE" to "START"
                    if DIN = '0' then
                        current_state <= START;
                        end if;
                        when START =>
                        -- condition from "START" to "DATA_READ"
                        --when clock counter == 22, we are ready to read data
                    if CNT_C = "10110" then
                        current_state <= DATA_READ;
                        end if;
                        when DATA_READ =>
                        -- condition from "DATA_READ" to "STOP"
                        -- if data counter == 8, all data was read
                    if CNT_D = "1000" then
                        current_state <= STOP;
                        end if;
                        when STOP =>
                        -- condition from "STOP"  to "VALIDATION"
                     if DIN = '1'  then
                        current_state <= VALIDATION;
                        end if;
                        when VALIDATION =>
                        -- condition from "VALIDATION" to "IDLE"
                        current_state <= IDLE;
                        when others =>
                        -- handle unexpected state
                        null;
                    end case;
                end if;
            end if;
        end process;
                    
-- outputs of the fsm in all states                   
        process (current_state)
    begin
        case current_state is
            when IDLE =>
                RDY <= '0';
                DCNT_EN <= '0';
                DOUT_VLD <= '0';
            when START =>
                RDY <= '0';
                DCNT_EN <= '1';
                DOUT_VLD <= '0';
            when DATA_READ =>
                RDY <= '1';
                DCNT_EN <= '1';
                DOUT_VLD <= '0';
            when STOP =>
                RDY <= '0';
                DCNT_EN <= '0';
                DOUT_VLD <= '0';
            when VALIDATION =>
                RDY <= '0';
                DCNT_EN <= '0';
                DOUT_VLD <= '1';
            when others =>
                RDY <= '0';
                DCNT_EN <= '0';
                DOUT_VLD <= '0';
        end case;
end process;

end architecture;
