proc Div {a b} {
   if {$b == 0} {
      error "Error generated by error" "Info String for error" 401
   } else {
      return [expr $a/$b]
   }
}

if {[catch {puts "Result = [Div 10 0]"} errmsg]} {
   puts "ErrorMsg: $errmsg"
   puts "ErrorCode: $errorCode"
   puts "ErrorInfo:\n$errorInfo\n"
}

if {[catch {puts "Result = [Div 10 2]"} errmsg]} {
   puts "ErrorMsg: $errmsg"
   puts "ErrorCode: $errorCode"
   puts "ErrorInfo:\n$errorInfo\n"
}