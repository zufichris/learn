import { colors, size } from "@/@types/theme";
import { cn } from "@/utils/cn";

interface ButtonProps extends React.ButtonHTMLAttributes<HTMLButtonElement> {
  isActive?: boolean;
  isLoading?: boolean;
  className?: string;
  color?: colors;
  size?: size;
}

const Button: React.FC<ButtonProps> = ({
  isActive = true,
  isLoading = false,
  color = "primary",
  size = "md",
  className,
  type = "button",
  onClick,
  children,
  ...props
}) => {
  
  const classes = cn(
    `x-4 py-2 rounded bg-${color}`,
    {
      "opacity-50 cursor-not-allowed": isLoading || !isActive||props.disabled,
      "text-sm": size === "sm",
      "text-base": size === "md",
      "text-lg": size === "lg",
    },
    className
  );
  return (
    <button
      type={type}
      onClick={isLoading ? undefined : onClick}
      disabled={!isActive || isLoading}
      className={classes}
      {...props}
    >
      {isLoading ? "Loading..." : children}
    </button>
  );
};

export default Button;
