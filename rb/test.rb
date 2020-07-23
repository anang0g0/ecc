class String
  def sha1hex
    SHA1.new(self).hexdigest
  end
end

# close ‚µ‚½‚¢‚¾‚¯ close ‚µ‚È‚­‚Ä‚à‚¢‚¢‚©‚È
# File.open(filename).read ‚Å‘ã—p‰»
def fileread(file)
  f = File.open(file)
  str = f.read
  f.close
  str
end

def usage
  STDERR.puts "usage: #{$0} [OPTION] [FILE]...
  -t, -v      check SHA1 sums against given list
      --status     do not output anything, status code shows success"
  exit 1
end

opt_check = false
opt_status = false

while ARGV[0] =~ /^-/
  $_ = ARGV.shift
  if ~/^-c/ or ~/^--check/
    opt_check = true
  elsif ~/^--status/
    opt_status = true
  else
    usage
  end
end

if opt_status == true and opt_check == false
  STDERR.puts "#{$0}: the --status option is meaningful only when verifying checksums(--check)"
  exit 1
end

require 'sha1'

if opt_check
  ck_count_total = 0
  ck_count_failed = 0
end

while file_str = gets(nil)
  if opt_check
    file_str.split("\n").each do |l|
      ck_count_total += 1
      sum1, fname = l.split
      sum2 = fileread(fname).shahex
      status = if sum1 == sum2
                 'OK'
               else
                 ck_count_failed += 1
                 'FAILED'
               end
      if opt_status
      else
        puts fname + ': ' + status
      end
    end
  else
    puts file_str.sha1hex + '  ' + ARGF.filename
    STATUS= file_str.sha1hex
  end
end

if opt_check and ck_count_failed > 0
  if opt_status
  else
    STDERR.puts "#{$0}: WARNING: #{ck_count_failed} of #{ck_count_total} computed checksum did NOT match"
  end
  exit 1
end
