module accumulator (
    input clk,
    input reset,
    input [7:0] in,

    output [7:0] out      
);

reg [7:0] dff;

always @(posedge clk) begin
    if (reset) begin
        dff <= 8'b0;
    end else begin
        dff <= in + out;
        $display ("Accumulate out = %d", dff);
    end
end

assign out = dff;

endmodule
